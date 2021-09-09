#include "common.h"
#include "core/internal/lifetime/TransientLifetime.h"

namespace sp
{
	TransientLifetime::TransientLifetime(sp::scoped_ptr<sp::ServiceEntry>& serviceEntry):m_serviceEntry(std::move(serviceEntry))
	{
	}

	TransientLifetime::~TransientLifetime()
	{
	}

	std::shared_ptr<void> TransientLifetime::GetInstance(sp::ref_ptr<IServiceContext> serviceContext)
	{
		auto sp = serviceContext->GetServiceProvider();
		return std::shared_ptr<void>(static_cast<LifetimeServiceEntry*>(m_serviceEntry.get())->CreateService(sp), static_cast<LifetimeServiceEntry*>(m_serviceEntry.get())->GetServiceDeleter());
	}
}
