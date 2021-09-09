#pragma once

#include "common.h"
#include "core/core.h"
#include "platform/input/IInput.h"

namespace sp
{
	namespace platform
	{
		class IApplication
		{
		public:
			virtual ~IApplication(){}

			virtual void OnCreate() = 0;
			virtual void OnResume() = 0;
			virtual void OnUpdate() = 0;
			virtual void OnSuspend() = 0;
			virtual void OnDestroy() = 0;

			virtual void OnInputConnected(sp::ref_ptr<sp::platform::input::IInput> input) = 0;
		};
	}
}