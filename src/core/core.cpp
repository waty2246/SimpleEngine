#include "common.h"
#include "core/utils.h"
#include "core/internal/ServiceProvider.h"

namespace sp
{
	ServiceResolveException::ServiceResolveException(const std::type_info& serviceTypeInfo, const size_t hashCode):_serviceTypeInfo(sp::make_scoped<std::type_index>(serviceTypeInfo)),_hashCode(hashCode)
	{
		CreateExceptionMessage();
	}

	const std::type_index& ServiceResolveException::GetServiceType() const
	{
		return *_serviceTypeInfo.get();
	}

	const std::string& ServiceResolveException::GetExceptionMessage() const
	{
		return _exceptionMessage;
	}

	const size_t ServiceResolveException::GetHashCode() const
	{
		return _hashCode;
	}

	const char* ServiceResolveException::what() const throw()
	{
		return _exceptionMessage.c_str();
	}

	void sp::ServiceResolveException::CreateExceptionMessage()
	{
		std::stringstream ss;
		ss << "Service Type "<< _serviceTypeInfo->name() <<" with hash code:"<< _hashCode <<" is not found. Please register it with IServiceCollection before being used.";
		_exceptionMessage = ss.str();
	}

	std::pair<std::shared_ptr<IServiceProvider>, std::shared_ptr<IServiceCollection>> CreateServiceProvider()
	{
		auto serviceProvider = std::make_shared<sp::ServiceProvider>();
		serviceProvider->Init();
		decltype(auto) serviceCollection = serviceProvider->GetServiceCollection();

		return 
		{
			std::dynamic_pointer_cast<IServiceProvider>(serviceProvider),
			serviceCollection
		};
	}
}

