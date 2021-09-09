#pragma once

#include "core/internal/IInstanceProducer.h"
#include "core/internal/lifetime/LifetimeServiceEntry.h"

namespace sp
{
	class TransientLifetime : public IInstanceProducer
	{
	public:
		TransientLifetime(sp::scoped_ptr<sp::ServiceEntry>& serviceEntry);
		virtual ~TransientLifetime();

		virtual std::shared_ptr<void> GetInstance(sp::ref_ptr<IServiceContext> serviceContext) override;

	private:
		const sp::scoped_ptr<ServiceEntry> m_serviceEntry;
	};
}
