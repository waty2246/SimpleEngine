#include "common.h"
#include "SystemApplication.h"
#include "platform/internal/input/KeyboardInputWrapper.h"
#include "core/IServiceProvider.h"
#include "core/IServiceCollection.h"
#include "platform/internal/SystemSpecsWrapper.h"
#include "platform/internal/WindowSpecsWrapper.h"
#include "platform/WindowProps.h"
#include "platform/external_modules.h"
#include "platform/IApplication.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace sp
{
    namespace platform
    {
        void SystemApplication::Init()
        {
			std::shared_ptr<sp::IServiceProvider> preServiceProvider;
			std::shared_ptr<sp::IServiceCollection> preServiceCollection;
			std::tie(preServiceProvider, preServiceCollection) = sp::CreateServiceProvider();

			std::shared_ptr<sp::IServiceProvider> postServiceProvider;
			std::shared_ptr<sp::IServiceCollection> postServiceCollection;
			std::tie(postServiceProvider, postServiceCollection) = sp::CreateServiceProvider();

			m_systemSpecs = new SystemSpecsWrapper(GetModuleHandle(nullptr));

			preServiceCollection->AddSingleton<SystemSpecs, SystemSpecsWrapper>([&]
				{
					return this->m_systemSpecs;
				});

			preServiceCollection->AddSingleton<WindowSpecs, WindowSpecsWrapper>([&]
				{
					return this->m_windowSpecification;
				});

			m_keyboardInput = sp::make_scoped<sp::platform::input::KeyboardInputWrapper>();
			auto windowProps = sp::make_scoped<WindowProps>();

			preServiceCollection->LockRegistration();
			SPCreatingWindow(windowProps);
			this->CreateSpecs(preServiceCollection,windowProps);
			SPConfigure(postServiceCollection, preServiceProvider);
			postServiceCollection->LockRegistration();

			std::tie(m_serviceProvider, m_serviceCollection) = sp::CreateServiceProvider();
			preServiceCollection->TransferTo(m_serviceCollection);
			postServiceCollection->TransferTo(m_serviceCollection);
			m_serviceCollection->LockRegistration();

			m_application = std::move(SPMain(m_serviceProvider));
			m_application->OnCreate();
			m_application->OnInputConnected(m_keyboardInput);
        }

        bool SystemApplication::Run()
        {
			ShowWindow(m_windowSpecification->GetWindowHandle(), SW_SHOW);
			SP_THROW_IF_FALSE(UpdateWindow(m_windowSpecification->GetWindowHandle()),"");

			MSG msg = { 0 };
			bool done = false;

			while (!done)
			{
				if (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
				{
					TranslateMessage(&msg);
					DispatchMessageW(&msg);
				}

				if (WM_QUIT == msg.message)
				{
					done = true;
				}
				else
				{
					m_application->OnUpdate();
				}
			}
			m_application->OnDestroy();
			return true;
        }

		sp::ref_ptr<sp::platform::input::KeyboardInputWrapper> SystemApplication::GetKeyboardInput()
		{
			return m_keyboardInput;
		}

		void SystemApplication::CreateSpecs(sp::ref_ptr<sp::IServiceCollection> preServiceCollection, sp::ref_ptr<WindowProps> windowProps)
		{
			int32_t renderWidth = windowProps->PreferRenderWidth;
			int32_t renderHeight = windowProps->PreferRenderHeight;
			int32_t windowWidth = 0;
			int32_t windowHeight = 0;
			int32_t windowPositionX = windowProps->PreferPositionX;
			int32_t windowPositionY = windowProps->PreferPositionY;
			ATOM windowClass = 0;
			HWND windowHandle = nullptr;

			WNDCLASSEX wex = { 0 };
			wex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
			wex.lpfnWndProc = reinterpret_cast<WNDPROC>(WndProc);
			wex.hInstance = m_systemSpecs->GetProgramHandle();
			wex.hIcon = LoadIcon(NULL, IDI_WINLOGO);
			wex.hIconSm = wex.hIcon;
			wex.hCursor = LoadCursor(NULL, IDC_HAND);
			wex.hbrBackground = CreateSolidBrush(RGB(100, 200, 100));
			wex.lpszClassName = L"SimpleEngine";
			wex.cbSize = sizeof(WNDCLASSEX);

			SP_THROW_IF_FALSE((windowClass = RegisterClassExW(&wex)) != FALSE,"");

			if (windowProps->IsFullScreen)
			{
				DWORD windowStyleEx = WS_EX_APPWINDOW;
				DWORD windowStyle = WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP;
				windowPositionX = 0;
				windowPositionY = 0;
				renderWidth = ::GetSystemMetrics(SM_CXSCREEN);
				renderHeight = ::GetSystemMetrics(SM_CYSCREEN);

				DEVMODE dmScreenSettings;
				ZeroMemory(&dmScreenSettings, sizeof(dmScreenSettings));
				dmScreenSettings.dmSize = sizeof(dmScreenSettings);
				dmScreenSettings.dmPelsWidth = (unsigned long)renderWidth;
				dmScreenSettings.dmPelsHeight = (unsigned long)renderHeight;
				dmScreenSettings.dmBitsPerPel = 32;
				dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

				::ChangeDisplaySettingsW(&dmScreenSettings, CDS_FULLSCREEN);

				windowHandle = ::CreateWindowExW(
					windowStyleEx,
					MAKEINTRESOURCE(windowClass),
					L"SimpleEngine",
					windowStyle,
					windowPositionX, windowPositionY,
					renderWidth, renderHeight,
					nullptr, nullptr, m_systemSpecs->GetProgramHandle(), reinterpret_cast<LPVOID>(this)
				);

				SP_THROW_IF_FALSE(windowHandle != nullptr,"");
				ShowCursor(FALSE);
			}
			else
			{
				DWORD windowStyleEx = WS_EX_APPWINDOW;
				DWORD windowStyle = WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME;
				RECT rect
				{
					0,
					0,
					renderWidth,
					renderHeight
				};

				SP_THROW_IF_FALSE(AdjustWindowRectEx(&rect, windowStyle, FALSE, windowStyleEx),"");

				windowWidth = rect.right - rect.left;
				windowHeight = rect.bottom - rect.top;

				windowHandle = CreateWindowExW(
					windowStyleEx,
					MAKEINTRESOURCE(windowClass),
					L"SimpleEngine",
					windowStyle,
					windowPositionX, windowPositionY,
					windowWidth, windowHeight,
					nullptr, nullptr, m_systemSpecs->GetProgramHandle(), reinterpret_cast<LPVOID>(this)
				);
				SP_THROW_IF_FALSE(windowHandle != nullptr,"");
			}

			m_windowSpecification = new WindowSpecsWrapper(
				windowHandle,
				windowWidth, 
				windowHeight,
				renderWidth,
				renderHeight,
				windowPositionX,
				windowPositionY,
				windowProps->IsFullScreen
			);
		}
    }
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static sp::platform::SystemApplication* systemApplication = nullptr;
	switch (msg)
	{
	case WM_CREATE:
	{
		systemApplication = reinterpret_cast<sp::platform::SystemApplication*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);

		return 0;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}

	case WM_CLOSE:
	{
		DestroyWindow(hwnd);
		return 0;
	}
	case WM_KEYDOWN:
	{
		systemApplication->GetKeyboardInput()->SetKeyDown(static_cast<sp::platform::input::KeyCode>(wParam));
		return 0;
	}
	case WM_KEYUP:
	{
		systemApplication->GetKeyboardInput()->SetKeyUp(static_cast<sp::platform::input::KeyCode>(wParam));
		return 0;
	}
	case WM_MOUSEMOVE:
	{
		return 0;
	}
	case WM_LBUTTONDOWN:
	{
		return 0;
	}
	case WM_MBUTTONDOWN:
	{
		return 0;
	}
	case WM_RBUTTONDOWN:
	{
		return 0;
	}
	case WM_LBUTTONUP:
	case WM_MBUTTONUP:
	case WM_RBUTTONUP:
	{
		return 0;
	}
	case WM_MOUSEHWHEEL:
	{
		return 0;
	}
	case WM_MOUSELEAVE:
	{
		return 0;
	}
	default:
	{
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	}
}
