#include "common.h"
#include "core/internal/lifetime/ScopedLifetime.h"
#include "core/internal/ScopedServiceProvider.h"

namespace sp
{
	ScopedLifetime::ScopedLifetime(sp::scoped_ptr<sp::ServiceEntry>& serviceEntry) : m_serviceEntry(std::move(serviceEntry))
	{
	}

	ScopedLifetime::~ScopedLifetime()
	{
	}

	std::shared_ptr<void> ScopedLifetime::GetInstance(sp::ref_ptr<IServiceContext> serviceContext)
	{
		auto sp = serviceContext->GetServiceProvider();
		if (serviceContext->IsScoped())
		{
			decltype(auto) scopedInstance = std::shared_ptr<void>(static_cast<LifetimeServiceEntry*>(m_serviceEntry.get())->CreateService(sp), static_cast<LifetimeServiceEntry*>(m_serviceEntry.get())->GetServiceDeleter());
			serviceContext->AddScopedInstance(m_serviceEntry->GetServiceTypeInfo(), scopedInstance);
			return scopedInstance;
		}

		if (!m_rootScopedInstance)
		{
			m_rootScopedInstance = std::shared_ptr<void>(static_cast<LifetimeServiceEntry*>(m_serviceEntry.get())->CreateService(sp), static_cast<LifetimeServiceEntry*>(m_serviceEntry.get())->GetServiceDeleter());
		}

		return m_rootScopedInstance;
	}
}