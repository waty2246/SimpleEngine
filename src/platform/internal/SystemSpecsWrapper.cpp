#include "common.h"
#include "platform/internal/SystemSpecsWrapper.h"

namespace sp
{
    namespace platform
    {
        SystemSpecsWrapper::SystemSpecsWrapper(HINSTANCE programHandle):
            SystemSpecs(programHandle)
        {
        }
    }
}

