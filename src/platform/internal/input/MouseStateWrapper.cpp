#include "common.h"
#include "platform/internal/input/MouseStateWrapper.h"

namespace sp
{
	namespace platform
	{
		namespace input
		{
			sp::math::Vector2F MouseState::GetMousePosition()
			{
				return sp::math::Vector2F();
			}

			float MouseState::GetDeltaWheel()
			{
				return 0.0f;
			}

			bool MouseState::IsLeftMouseButtonPressed()
			{
				return false;
			}

			bool MouseState::IsRightMouseButtonPressed()
			{
				return false;
			}

			bool MouseState::IsMiddleMouseButtonPressed()
			{
				return false;
			}
		}
	}
}
