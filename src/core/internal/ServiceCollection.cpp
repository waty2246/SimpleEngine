#include "common.h"
#include "core/internal/ServiceCollection.h"
#include "core/internal/lifetime/TransientLifetime.h"
#include "core/internal/lifetime/ScopedLifetime.h"
#include "core/internal/lifetime/SingletonLifetime.h"

namespace sp
{
	ServiceCollection::ServiceCollection():_hashLocked(false)
	{
	}

	void ServiceCollection::LockRegistration()
	{
		_hashLocked = true;
	}

	bool ServiceCollection::IsLockForRegistration() const
	{
		return _hashLocked;
	}

	bool ServiceCollection::Contains(size_t hashCode)
	{
		return m_instanceProducers.count(hashCode)>0;
	}

	IInstanceProducer* ServiceCollection::GetInstanceProducer(size_t hashCode)
	{
		if (Contains(hashCode))
		{
			return m_instanceProducers[hashCode].get();
		}

		return nullptr;
	}

	void ServiceCollection::TransferTo(sp::ref_ptr<IServiceCollection> serviceCollection)
	{
		if (serviceCollection->IsLockForRegistration())
		{
			SP_THROW_EXCEPT("Cannot transfer service, Service Collection is closed for registration.");
		}

		auto sc = static_cast<ServiceCollection*>(serviceCollection.get());
		sc->m_instanceProducers.insert(std::make_move_iterator(m_instanceProducers.begin()),std::make_move_iterator(m_instanceProducers.end()));
		m_instanceProducers.clear();
	}

	ServiceCollection::~ServiceCollection()
	{
	}

	std::shared_ptr<IServiceProvider> sp::ServiceCollection::GetServiceProvider()
	{
		return m_serviceProvider.lock();
	}

	void sp::ServiceCollection::AddServiceEntry(sp::scoped_ptr<sp::ServiceEntry>& serviceEntry)
	{
		if (_hashLocked) throw std::exception("Service Collection has been blocked for registration");

		auto serviceLifetime = serviceEntry->GetServiceLifetime();
		auto hashCode = HashCode(serviceEntry->GetServiceTypeInfo());
		switch (serviceLifetime)
		{
		case ServiceLifetime::Singleton:
			m_instanceProducers[hashCode] = std::move(sp::make_scoped<SingletonLifetime>(serviceEntry));
			break;
		case ServiceLifetime::Scoped:
			m_instanceProducers[hashCode] = std::move(sp::make_scoped<ScopedLifetime>(serviceEntry));
			break;
		default://TRANSIENT
			m_instanceProducers[hashCode] = std::move(sp::make_scoped<TransientLifetime>(serviceEntry));
		}
	}

	void ServiceCollection::SetServiceProvider(std::shared_ptr<IServiceProvider> serviceProvider)
	{
		m_serviceProvider = serviceProvider;
	}
}

