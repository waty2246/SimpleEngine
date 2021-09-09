#pragma once

#include <cstdint>

namespace sp
{
    namespace platform
    {
        struct WindowProps
        {
            int32_t PreferRenderWidth = 1200;
            int32_t PreferRenderHeight = 800;
            int32_t PreferPositionX = 0;
            int32_t PreferPositionY = 0;
            bool IsFullScreen = true;
        };
    }
}