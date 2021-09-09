#include "common.h"
#include "core/internal/ScopedServiceProvider.h"

namespace sp
{
	ScopedServiceProvider::ScopedServiceProvider(std::shared_ptr<ServiceCollection> serviceCollection) : m_serviceCollection(serviceCollection)
	{
	}

	ScopedServiceProvider::~ScopedServiceProvider()
	{
	}

	std::shared_ptr<IServiceProvider> ScopedServiceProvider::CreateScope()
	{
		return std::make_shared<ScopedServiceProvider>(m_serviceCollection);
	}

	void ScopedServiceProvider::AddScopedInstance(const std::type_index& serviceTypeInfo,std::shared_ptr<void> scopedService)
	{
		auto hashCode = HashCode(serviceTypeInfo);
		m_scopedInstance[hashCode] = std::move(scopedService);
	}

	std::shared_ptr<IServiceProvider> ScopedServiceProvider::GetServiceProvider()
	{
		return shared_from_this();
	}

	std::shared_ptr<void> ScopedServiceProvider::GetService(const std::type_info& serviceTypeInfo, bool isThrowExcept)
	{
		const auto hashCode = HashCode(serviceTypeInfo);
		if (m_scopedInstance.count(hashCode) > 0)
		{
			return m_scopedInstance[hashCode];
		}

		decltype(auto) instanceProducer = m_serviceCollection->GetInstanceProducer(hashCode);
		if (instanceProducer != nullptr)
		{
			return instanceProducer->GetInstance(std::dynamic_pointer_cast<sp::IServiceContext>(shared_from_this()));
		}

		if (isThrowExcept)
		{
			SP_THROW_EXCEPT(ServiceResolveException(serviceTypeInfo, hashCode).what());
		}
		
		return {};
	}
	bool ScopedServiceProvider::IsScoped()
	{
		return true;
	}
}

