#include "common.h"
#include "core/internal/ServiceProvider.h"
#include "core/internal/ScopedServiceProvider.h"

namespace sp
{
    ServiceProvider::ServiceProvider():m_serviceCollection(std::make_shared<ServiceCollection>())
    {
    }

    std::shared_ptr<IServiceCollection> ServiceProvider::GetServiceCollection()
    {
        return m_serviceCollection;
    }

    ServiceProvider::~ServiceProvider()
    {
    }

    void ServiceProvider::Init()
    {
        m_serviceCollection->SetServiceProvider(shared_from_this());
    }

    std::shared_ptr<IServiceProvider> ServiceProvider::CreateScope()
    {
        CheckServiceRegistrationBlocked();
        return std::make_shared<ScopedServiceProvider>(m_serviceCollection);
    }

    std::shared_ptr<void> ServiceProvider::GetService(const std::type_info& serviceTypeInfo, bool isThrowExcept)
    {
        CheckServiceRegistrationBlocked();
        const auto hashCode = HashCode(serviceTypeInfo);
        decltype(auto) instanceProducer = m_serviceCollection->GetInstanceProducer(hashCode);
        if (instanceProducer !=nullptr)
        {
            return instanceProducer->GetInstance(std::dynamic_pointer_cast<sp::IServiceContext>(shared_from_this()));
        }

        if (isThrowExcept)
        {
            SP_THROW_EXCEPT(ServiceResolveException(serviceTypeInfo, hashCode).what());
        }

        return {};
    }

    void ServiceProvider::CheckServiceRegistrationBlocked()
    {
        if (!m_serviceCollection->IsLockForRegistration())
        {
            SP_THROW_EXCEPT("Cannot create service, Service Collection is opened for registration.");
        }
    }

    bool ServiceProvider::IsScoped()
    {
        return false;
    }

    void ServiceProvider::AddScopedInstance(const std::type_index& serviceTypeInfo, std::shared_ptr<void> scopedService)
    {
    }

    std::shared_ptr<IServiceProvider> ServiceProvider::GetServiceProvider()
    {
        return shared_from_this();
    }
}
