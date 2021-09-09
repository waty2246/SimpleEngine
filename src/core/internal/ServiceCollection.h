#pragma once

#include "core/IServiceCollection.h"
#include "core/internal/IInstanceProducer.h"

namespace sp
{
	class ServiceCollection : public IServiceCollection
	{
	public:
		ServiceCollection();
		virtual ~ServiceCollection();

		virtual void LockRegistration() override;
		virtual bool IsLockForRegistration() const override;
		virtual void TransferTo(sp::ref_ptr<IServiceCollection> serviceCollection) override;

		bool Contains(size_t hashCode);
		IInstanceProducer* GetInstanceProducer(size_t hashCode);
		
	protected:
		virtual std::shared_ptr<IServiceProvider> GetServiceProvider() override;
		virtual void AddServiceEntry(sp::scoped_ptr<sp::ServiceEntry>& serviceEntry) override;

	private:
		void SetServiceProvider(std::shared_ptr<IServiceProvider> serviceProvider);
		friend class ServiceProvider;

	private:
		bool _hashLocked;
		std::map<size_t, sp::scoped_ptr<IInstanceProducer>> m_instanceProducers;
		std::weak_ptr<IServiceProvider> m_serviceProvider;
	};
}