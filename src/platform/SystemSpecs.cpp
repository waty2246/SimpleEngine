#include "common.h"
#include "platform/SystemSpecs.h"

namespace sp
{
	namespace platform
	{
		SystemSpecs::SystemSpecs(HINSTANCE programHandle): m_programHandle(programHandle)
		{
		}

		HINSTANCE SystemSpecs::GetProgramHandle() const
		{
			return m_programHandle;
		}
	}
}