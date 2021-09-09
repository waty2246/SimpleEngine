#pragma once

#include "platform/WindowSpecs.h"

namespace sp
{
	namespace platform
	{
		class WindowSpecsWrapper : public WindowSpecs
		{
		public:
			WindowSpecsWrapper(
				HWND windowHandle,
				int32_t windowWidth,
				int32_t windowHeight,
				int32_t renderWidth,
				int32_t renderHeight,
				int32_t windowPositionX,
				int32_t windowPositionY,
				bool isFullscreen
			);
		};
	}
}