#include "common.h"
#include "platform/WindowSpecs.h"

namespace sp
{
	namespace platform
	{
		WindowSpecs::WindowSpecs(
			HWND windowHandle, 
			int32_t windowWidth, 
			int32_t windowHeight, 
			int32_t renderWidth, 
			int32_t renderHeight, 
			int32_t windowPositionX, 
			int32_t windowPositionY,
			bool isFullscreen
		):
			m_windowHandle(windowHandle),
			m_windowWidth(windowWidth),
			m_windowHeight(windowHeight),
			m_renderWidth(renderWidth),
			m_renderHeight(renderHeight),
			m_windowPositionX(windowPositionX),
			m_windowPositionY(windowPositionY),
			m_isFullscreen(isFullscreen)
		{
		}

		HWND WindowSpecs::GetWindowHandle()
		{
			return m_windowHandle;
		}

		int32_t WindowSpecs::GetWindowWidth()
		{
			return m_renderWidth;
		}

		int32_t WindowSpecs::GetWindowHeight()
		{
			return m_windowHeight;
		}

		int32_t WindowSpecs::GetRenderWidth()
		{
			return m_renderWidth;
		}

		int32_t WindowSpecs::GetRenderHeight()
		{
			return m_renderHeight;
		}

		int32_t WindowSpecs::GetWindowPositionX()
		{
			return m_windowPositionX;
		}

		int32_t WindowSpecs::GetWindowPositionY()
		{
			return m_windowPositionY;
		}

		bool WindowSpecs::IsFullscreen()
		{
			return m_isFullscreen;
		}
	}
}