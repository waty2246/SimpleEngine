#pragma once

#include "core/logging/ILoggerProvider.h"

namespace sp
{
	namespace logging
	{
		class ILoggerFactory
		{
		public:
			virtual sp::scoped_ptr<ILogger> CreateLogger(std::wstring context) = 0;
			virtual void AddLoggerProvider(sp::ref_ptr<ILoggerProvider> loggerProvider) = 0;
		};
	}
}