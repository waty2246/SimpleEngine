#include "common.h"
#include "core/internal/lifetime/SingletonLifetime.h"

namespace sp
{
	SingletonLifetime::SingletonLifetime(sp::scoped_ptr<sp::ServiceEntry>& serviceEntry) : m_serviceEntry(std::move(serviceEntry))
	{
	}

	SingletonLifetime::~SingletonLifetime()
	{
	}

	std::shared_ptr<void> SingletonLifetime::GetInstance(sp::ref_ptr<IServiceContext> serviceContext)
	{
		auto sp = serviceContext->GetServiceProvider();
		if (!m_singleton)
		{
			return m_singleton=std::shared_ptr<void>(static_cast<LifetimeServiceEntry*>(m_serviceEntry.get())->CreateService(sp), static_cast<LifetimeServiceEntry*>(m_serviceEntry.get())->GetServiceDeleter());
		}

		return m_singleton;
	}
}