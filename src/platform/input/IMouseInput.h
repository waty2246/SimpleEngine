#pragma once

#include "platform/input/IInput.h"

namespace sp
{
	namespace platform
	{
		namespace input
		{
			class IMouseInput : public IInput
			{
			public:
				virtual uint32_t GetInputId() override final;

				virtual ~IMouseInput() {}

				static const uint32_t MOUSE_INPUT_ID = 2;
			};
		}
	}
}