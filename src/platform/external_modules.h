#pragma once

#include "core/core.h"

namespace sp
{
	namespace platform
	{
		class IApplication;
		struct WindowProps;
	}
}

extern void SPCreatingWindow(sp::ref_ptr<sp::platform::WindowProps> windowProps);
extern void SPConfigure(sp::ref_ptr<sp::IServiceCollection> configServiceCollection,sp::ref_ptr<sp::IServiceProvider> systemServiceProvider);
extern std::shared_ptr<sp::platform::IApplication> SPMain(sp::ref_ptr<sp::IServiceProvider> serviceProvider);