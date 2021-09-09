#pragma once

#include <cstdint>

namespace sp
{
	namespace platform
	{
		namespace input
		{
			class IInput
			{
			public:
				virtual uint32_t GetInputId() = 0;
			};
		}
	}
}