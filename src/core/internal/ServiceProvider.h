#pragma once

#include "core/IServiceProvider.h"
#include "core/internal/IServiceContext.h"
#include "core/internal/ServiceCollection.h"

namespace sp
{
	class ServiceProvider:public IServiceProvider,public IServiceContext
	{
	public:
		ServiceProvider();
		virtual ~ServiceProvider();

		void Init();
		virtual bool IsScoped() override;
		virtual void AddScopedInstance(const std::type_index& serviceTypeInfo, std::shared_ptr<void> scopedService) override;
		virtual std::shared_ptr<IServiceProvider> GetServiceProvider() override;

		std::shared_ptr<IServiceCollection> GetServiceCollection();
		virtual std::shared_ptr<IServiceProvider> CreateScope() override;

	protected:
		virtual std::shared_ptr<void> GetService(const std::type_info& serviceTypeInfo, bool isThrowExcept) override;

	private:
		void CheckServiceRegistrationBlocked();

	private:
		const std::shared_ptr<ServiceCollection> m_serviceCollection;		
	};
}