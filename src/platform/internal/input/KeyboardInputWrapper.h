#pragma once

#include "platform/input/IKeyboardInput.h"
#include "platform/input/IKeyboardState.h"

namespace sp
{
	namespace platform
	{
		namespace input
		{
			class KeyboardInputWrapper : public IKeyboardInput
			{
			public:
				void SetKeyDown(KeyCode keyCode);
				void SetKeyUp(KeyCode keyCode);

			};
		}
	}
}