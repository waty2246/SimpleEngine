#include "common.h"
#include "platform/internal/WindowSpecsWrapper.h"

namespace sp
{
    namespace platform
    {
        WindowSpecsWrapper::WindowSpecsWrapper(
            HWND windowHandle,
            int32_t windowWidth,
            int32_t windowHeight,
            int32_t renderWidth,
            int32_t renderHeight,
            int32_t windowPositionX,
            int32_t windowPositionY,
            bool isFullscreen
        ): 
            WindowSpecs(windowHandle, windowWidth, windowHeight, renderWidth, renderHeight, windowPositionX, windowPositionY,isFullscreen)
        {
        }
    }
}



