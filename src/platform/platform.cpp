#include "common.h"
#include "platform/platform.h"
#include "platform/input/IMouseInput.h"
#include "platform/input/IKeyboardInput.h"

extern "C"
{
	__declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
	__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
}

namespace sp
{
	namespace platform
	{
		namespace input
		{
			uint32_t IMouseInput::GetInputId()
			{
				return MOUSE_INPUT_ID;
			}
				
			uint32_t IKeyboardInput::GetInputId()
			{
				return KEYBOARD_INPUT_ID;
			}
		}
	}
}
