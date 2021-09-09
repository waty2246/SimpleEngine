#pragma once

#include "math/Vector2.h"

namespace sp
{
	namespace platform
	{
		namespace input
		{
			class IMouseState
			{
			public:
				virtual sp::math::Vector2F GetMousePosition() = 0;
				virtual float GetDeltaWheel() = 0;
				virtual bool IsLeftMouseButtonPressed() = 0;
				virtual bool IsRightMouseButtonPressed() = 0;
				virtual bool IsMiddleMouseButtonPressed() = 0;

				virtual ~IMouseState(){}
			};
		}
	}
}