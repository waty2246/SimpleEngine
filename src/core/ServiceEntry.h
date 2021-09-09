#pragma once

#include "core/utils.h"
#include "core/ServiceLifetime.h"
#include "core/IServiceProvider.h"

namespace sp
{
	class ServiceEntry
	{
	public:
		ServiceEntry(ServiceLifetime lifetime);
		ServiceEntry(service_factory_0_fn serviceFactoryFn, ServiceLifetime lifetime);
		ServiceEntry(service_factory_1_fn serviceFactoryFn, ServiceLifetime lifetime);
		~ServiceEntry();

		const ServiceLifetime& GetServiceLifetime() const;
		const std::type_index& GetServiceTypeInfo() const;

	private:
		friend class IServiceCollection;
		template<typename TServiceType, typename TServiceImplementation>
		void InitInjection();

		template<typename TServiceType, typename TServiceImplementation>
		void InitFactory0();

		template<typename TServiceType, typename TServiceImplementation>
		void InitFactory1();

		template<typename TServiceType, typename TServiceImplementation>
		void InitDeleter();

	protected:
		const ServiceLifetime m_lifetime;
		sp::scoped_ptr<std::type_index> m_serviceTypeInfo;
		create_service_fn m_createServiceClosure;
		delete_service_act m_deleteServiceClosure;
		service_factory_0_fn m_serviceFactory0Fn;
		service_factory_1_fn m_serviceFactory1Fn;
	};

	inline ServiceEntry::ServiceEntry( ServiceLifetime lifetime) : m_lifetime(lifetime)
	{
	}

	inline ServiceEntry::ServiceEntry(service_factory_0_fn serviceFactoryFn, ServiceLifetime lifetime) : m_lifetime(lifetime), m_serviceFactory0Fn(serviceFactoryFn)
	{
	}

	inline ServiceEntry::ServiceEntry(service_factory_1_fn serviceFactoryFn, ServiceLifetime lifetime) : m_lifetime(lifetime), m_serviceFactory1Fn(serviceFactoryFn)
	{
	}

	template<typename TServiceType, typename TServiceImplementation>
	inline void ServiceEntry::InitInjection()
	{
		m_createServiceClosure = [this](sp::ref_ptr<IServiceProvider> sp) -> raw_pointer
		{
			return static_cast<raw_pointer>(typename TServiceImplementation::CreateSelf(sp.get()));
		};
	}

	template<typename TServiceType, typename TServiceImplementation>
	inline void ServiceEntry::InitFactory0()
	{
		m_createServiceClosure = [this](sp::ref_ptr<IServiceProvider> sp) -> raw_pointer
		{
			return m_serviceFactory0Fn();
		};
	}

	template<typename TServiceType, typename TServiceImplementation>
	inline void ServiceEntry::InitFactory1()
	{
		m_createServiceClosure = [this](sp::ref_ptr<IServiceProvider> sp) -> raw_pointer
		{
			return m_serviceFactory1Fn(sp.get());
		};
	}

	template<typename TServiceType, typename TServiceImplementation>
	inline void ServiceEntry::InitDeleter()
	{
		m_serviceTypeInfo = sp::make_scoped<std::type_index>(typeid(TServiceType));
		m_deleteServiceClosure = [&](raw_pointer servicePtr) -> void
		{
			if (servicePtr != nullptr)
			{
				delete static_cast<TServiceImplementation*>(servicePtr);
				servicePtr = nullptr;
			}
		};
	}
}