#pragma once

#include "core/utils.h"
#include "core/ServiceEntry.h"

namespace sp
{
	class LifetimeServiceEntry : public ServiceEntry
	{
	public:
		raw_pointer CreateService(sp::ref_ptr<IServiceProvider> sp);
		delete_service_act GetServiceDeleter();
	};
}