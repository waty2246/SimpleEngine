#pragma once

namespace sp
{
    namespace render
    {
        /// <summary>
        /// Manage access to the core inner functions of the Graphics API, such as creating graphics data structures like textures, buffers, queues, pipelines.
        /// </summary>
        class ILogicalDevice
        {
        public:
            virtual ~ILogicalDevice(){}
        };
    }
}
