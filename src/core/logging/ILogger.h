#pragma once

#include "core/core.h"

namespace sp
{
	namespace logging
	{
		enum class LogLevel
		{
			Debug,
			Info,
			Warning,
			Error,
			Fatal
		};

		class ILogger
		{
		public:
			virtual void Log(LogLevel logLevel,std::wstring logMessage) = 0;
		};
	}
}