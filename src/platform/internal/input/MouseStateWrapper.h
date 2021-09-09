#pragma once

#include "platform/input/IMouseState.h"

namespace sp
{
	namespace platform
	{
		namespace input
		{
			class MouseState : public IMouseState
			{
			public:
				virtual sp::math::Vector2F GetMousePosition() override;

				virtual float GetDeltaWheel() override;

				virtual bool IsLeftMouseButtonPressed() override;

				virtual bool IsRightMouseButtonPressed() override;

				virtual bool IsMiddleMouseButtonPressed() override;

			};
		}
	}
}