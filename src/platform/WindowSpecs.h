#pragma once

#include "common.h"

namespace sp
{
    namespace platform
    {
        class WindowSpecs
        {
        public:
            WindowSpecs(
                HWND windowHandle,
                int32_t windowWidth,
                int32_t windowHeight,
                int32_t renderWidth,
                int32_t renderHeight,
                int32_t windowPositionX,
                int32_t windowPositionY,
                bool isFullscreen
            );

            HWND        GetWindowHandle();
            int32_t		GetWindowWidth();
            int32_t		GetWindowHeight();
            int32_t		GetRenderWidth();
            int32_t		GetRenderHeight();
            int32_t		GetWindowPositionX();
            int32_t		GetWindowPositionY();
            bool        IsFullscreen();

        protected:
            HWND m_windowHandle;
            int32_t m_windowWidth;
            int32_t m_windowHeight;
            int32_t m_renderWidth;
            int32_t m_renderHeight;
            int32_t m_windowPositionX;
            int32_t m_windowPositionY;
            bool m_isFullscreen;
        };
    }
}