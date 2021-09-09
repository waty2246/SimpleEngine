#pragma once

namespace sp
{
    namespace render
    {
        /// <summary>
        /// Used to query physical device specific details such as video memory size and features support (MSAA ... ).
        /// </summary>
        class IPhysicalDevice
        {
        public:
            virtual ~IPhysicalDevice(){}
        };
    }
}