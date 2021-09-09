#pragma once

#include "platform/input/IInput.h"

namespace sp
{
	namespace platform
	{
		namespace input
		{
			class IKeyboardInput : public IInput
			{
			public:
				virtual uint32_t GetInputId() override;

				static const uint32_t KEYBOARD_INPUT_ID = 1;

				virtual ~IKeyboardInput() {}
			};
		}
	}
}