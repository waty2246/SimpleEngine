#pragma once

#include "core/internal/IInstanceProducer.h"
#include "core/internal/lifetime/LifetimeServiceEntry.h"

namespace sp
{
	class SingletonLifetime : public IInstanceProducer
	{
	public:
		SingletonLifetime(sp::scoped_ptr<sp::ServiceEntry>& serviceEntry);
		virtual ~SingletonLifetime();

		virtual std::shared_ptr<void> GetInstance(sp::ref_ptr<IServiceContext> serviceContext) override;

	private:
		const sp::scoped_ptr<ServiceEntry> m_serviceEntry;
		std::shared_ptr<void> m_singleton;
	};
}