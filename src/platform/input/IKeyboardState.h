#pragma once

#include <Windows.h>
#include <cstdint>

namespace sp
{
	namespace platform
	{
		namespace input
		{
			enum class KeyCode : uint8_t
			{
				NONE = 0,
				SHIFT = VK_SHIFT,
				ALT = VK_MENU,
				CONTROL = VK_CONTROL,
				LEFT = VK_LEFT,
				RIGHT = VK_RIGHT,
				UP = VK_UP,
				DOWN = VK_DOWN,
				ENTER = VK_RETURN,
				A = 0x41, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
				F1 = VK_F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
				ESCAPE = VK_ESCAPE,
				UNKNOWN = 255
			};

			/// <summary>
			/// Current keystate updated every frame by IKeyboardInput.
			/// </summary>
			class IKeyboardState
			{
			public:
				virtual bool IsKeyPressed(KeyCode keyCode) = 0;

				virtual ~IKeyboardState(){}
			};
		}
	}
}