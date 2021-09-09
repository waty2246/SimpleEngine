#pragma once

#include "core/utils.h"
#include "core/ServiceLifetime.h"
#include "core/IServiceProvider.h"
#include "core/ServiceEntry.h"

namespace sp
{
	class IServiceCollection
	{
	public:
		virtual ~IServiceCollection() {}

		template<typename TServiceType, typename TServiceImplementation>
		IServiceCollection* Register(ServiceLifetime lifetime);

		template<typename TServiceType, typename TServiceImplementation>
		IServiceCollection* Register(service_factory_0_fn serviceFactoryFn, ServiceLifetime lifetime);

		template<typename TServiceType, typename TServiceImplementation>
		IServiceCollection* Register(service_factory_1_fn serviceFactoryFn,ServiceLifetime lifetime);

		template<typename TServiceType, typename TServiceImplementation>
		IServiceCollection* AddTransient();

		template<typename TServiceType, typename TServiceImplementation>
		IServiceCollection* AddTransient(service_factory_0_fn serviceFactoryFn);

		template<typename TServiceType, typename TServiceImplementation>
		IServiceCollection* AddTransient(service_factory_1_fn serviceFactoryFn);

		template<typename TServiceType, typename TServiceImplementation>
		IServiceCollection* AddScoped();

		template<typename TServiceType, typename TServiceImplementation>
		IServiceCollection* AddScoped(service_factory_0_fn serviceFactoryFn);

		template<typename TServiceType, typename TServiceImplementation>
		IServiceCollection* AddScoped(service_factory_1_fn serviceFactoryFn);

		template<typename TServiceType, typename TServiceImplementation>
		IServiceCollection* AddSingleton();

		template<typename TServiceType, typename TServiceImplementation>
		IServiceCollection* AddSingleton(service_factory_0_fn serviceFactoryFn);

		template<typename TServiceType, typename TServiceImplementation>
		IServiceCollection* AddSingleton(service_factory_1_fn serviceFactoryFn);

		virtual void LockRegistration() = 0;
		virtual bool IsLockForRegistration() const = 0;
		virtual void TransferTo(sp::ref_ptr<IServiceCollection> serviceCollection) = 0;

	protected:
		virtual std::shared_ptr<IServiceProvider> GetServiceProvider() = 0;
		virtual void AddServiceEntry(sp::scoped_ptr<sp::ServiceEntry>& serviceEntry) = 0;
	};

	template<typename TServiceType, typename TServiceImplementation>
	inline IServiceCollection* IServiceCollection::Register(ServiceLifetime lifetime)
	{
		Implements<TServiceType, TServiceImplementation>();

		decltype(auto) serviceEntry = sp::make_scoped<ServiceEntry>(lifetime);
		serviceEntry->InitDeleter<TServiceType, TServiceImplementation>();
		serviceEntry->InitInjection<TServiceType, TServiceImplementation>();

		AddServiceEntry(serviceEntry);
		return this;
	}

	template<typename TServiceType, typename TServiceImplementation>
	inline IServiceCollection* IServiceCollection::Register(service_factory_0_fn serviceFactoryFn, ServiceLifetime lifetime)
	{
		Implements<TServiceType, TServiceImplementation>();

		decltype(auto) serviceEntry = sp::make_scoped<ServiceEntry>(serviceFactoryFn, lifetime);
		serviceEntry->InitDeleter<TServiceType, TServiceImplementation>();
		serviceEntry->InitFactory0<TServiceType, TServiceImplementation>();

		AddServiceEntry(serviceEntry);
		return this;
	}

	template<typename TServiceType, typename TServiceImplementation>
	inline IServiceCollection* IServiceCollection::Register(service_factory_1_fn serviceFactoryFn, ServiceLifetime lifetime)
	{
		Implements<TServiceType, TServiceImplementation>();

		decltype(auto) serviceEntry = sp::make_scoped<ServiceEntry>(serviceFactoryFn, lifetime);
		serviceEntry->InitDeleter<TServiceType, TServiceImplementation>();
		serviceEntry->InitFactory1<TServiceType, TServiceImplementation>();

		AddServiceEntry(serviceEntry);
		return this;
	}

	template<typename TServiceType, typename TServiceImplementation>
	inline IServiceCollection* IServiceCollection::AddTransient()
	{
		return Register<TServiceType, TServiceImplementation>(ServiceLifetime::Transient);
	}

	template<typename TServiceType, typename TServiceImplementation>
	inline IServiceCollection* IServiceCollection::AddTransient(service_factory_0_fn serviceFactoryFn)
	{
		return Register<TServiceType, TServiceImplementation>(serviceFactoryFn, ServiceLifetime::Transient);
	}

	template<typename TServiceType, typename TServiceImplementation>
	inline IServiceCollection* IServiceCollection::AddTransient(service_factory_1_fn serviceFactoryFn)
	{
		return Register<TServiceType, TServiceImplementation>(serviceFactoryFn,ServiceLifetime::Transient);
	}

	template<typename TServiceType, typename TServiceImplementation>
	inline IServiceCollection* IServiceCollection::AddScoped()
	{
		return Register<TServiceType, TServiceImplementation>(ServiceLifetime::Scoped);
	}

	template<typename TServiceType, typename TServiceImplementation>
	inline IServiceCollection* IServiceCollection::AddScoped(service_factory_0_fn serviceFactoryFn)
	{
		return Register<TServiceType, TServiceImplementation>(serviceFactoryFn, ServiceLifetime::Scoped);
	}

	template<typename TServiceType, typename TServiceImplementation>
	inline IServiceCollection* IServiceCollection::AddScoped(service_factory_1_fn serviceFactoryFn)
	{
		return Register<TServiceType, TServiceImplementation>(serviceFactoryFn,ServiceLifetime::Scoped);
	}

	template<typename TServiceType, typename TServiceImplementation>
	inline IServiceCollection* IServiceCollection::AddSingleton()
	{
		return Register<TServiceType, TServiceImplementation>(ServiceLifetime::Singleton);
	}

	template<typename TServiceType, typename TServiceImplementation>
	inline IServiceCollection* IServiceCollection::AddSingleton(service_factory_0_fn serviceFactoryFn)
	{
		return Register<TServiceType, TServiceImplementation>(serviceFactoryFn, ServiceLifetime::Singleton);
	}

	template<typename TServiceType, typename TServiceImplementation>
	inline IServiceCollection* IServiceCollection::AddSingleton(service_factory_1_fn serviceFactoryFn)
	{
		return Register<TServiceType, TServiceImplementation>(serviceFactoryFn,ServiceLifetime::Singleton);
	}
}