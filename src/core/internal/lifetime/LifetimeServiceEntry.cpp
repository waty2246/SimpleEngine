#include "common.h"
#include "core/internal/lifetime/LifetimeServiceEntry.h"

namespace sp
{
	raw_pointer LifetimeServiceEntry::CreateService(sp::ref_ptr<IServiceProvider> sp)
	{
		return m_createServiceClosure(sp);
	}

	delete_service_act LifetimeServiceEntry::GetServiceDeleter()
	{
		return m_deleteServiceClosure;
	}
}