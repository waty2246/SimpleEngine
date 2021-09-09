#pragma once

#include "platform/SystemSpecs.h"

namespace sp
{
	namespace platform
	{
		class SystemSpecsWrapper : public SystemSpecs
		{
		public:
			SystemSpecsWrapper(HINSTANCE programHandle);

		};
	}
}