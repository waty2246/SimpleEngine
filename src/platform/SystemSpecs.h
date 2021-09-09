#pragma once

#include <Windows.h>

namespace sp
{
	namespace platform
	{
		class SystemSpecs
		{
		public:
			SystemSpecs(HINSTANCE programHandle);
			
			HINSTANCE GetProgramHandle() const;

		private:
			HINSTANCE m_programHandle;
		};
	}
}