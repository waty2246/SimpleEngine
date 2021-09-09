#include "common.h"
#include "platform/internal/SystemApplication.h"

int APIENTRY WinMain(_In_ HINSTANCE hInst, _In_opt_ HINSTANCE hInstPrev, _In_ PSTR cmdline, _In_ int cmdshow)
{
	try
	{
		std::shared_ptr<sp::platform::SystemApplication> systemApplication = std::make_shared<sp::platform::SystemApplication>();
		systemApplication->Init();

		if (!systemApplication->Run())
		{
			return -2;
		}
	}
	catch (...)
	{
		return -1;
	}

	return 0;
}