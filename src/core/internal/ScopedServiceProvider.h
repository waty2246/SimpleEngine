#pragma once

#include "core/IServiceProvider.h"
#include "core/internal/IServiceContext.h"
#include "core/internal/ServiceCollection.h"

namespace sp
{
	class ScopedServiceProvider:public IServiceProvider,public IServiceContext
	{
	public:
		ScopedServiceProvider(std::shared_ptr<ServiceCollection> serviceCollection);
		~ScopedServiceProvider();

		virtual bool IsScoped() override;
		virtual std::shared_ptr<IServiceProvider> CreateScope() override;
		virtual void AddScopedInstance(const std::type_index& serviceTypeInfo,std::shared_ptr<void> scopedService) override;
		virtual std::shared_ptr<IServiceProvider> GetServiceProvider() override;

	protected:
		virtual std::shared_ptr<void> GetService(const std::type_info& serviceTypeInfo,bool isThrowExcept) override;

	private:
		const std::shared_ptr<ServiceCollection> m_serviceCollection;
		std::map<hash_code_t, std::shared_ptr<void>> m_scopedInstance;
	};
}