#pragma once

#include <memory>

namespace sp
{
	class IServiceProvider: public std::enable_shared_from_this<IServiceProvider>
	{
	public:
		template<typename TServiceType>
		std::shared_ptr<TServiceType> GetService();

		template<typename TServiceType>
		std::shared_ptr<TServiceType> GetService(nullptr_t);

		template<typename ObjectType>
		std::shared_ptr<ObjectType> FillObject();

		virtual std::shared_ptr<IServiceProvider> CreateScope() = 0;

		virtual ~IServiceProvider() {}

	protected:
		virtual std::shared_ptr<void> GetService(const std::type_info& serviceTypeInfo,bool isThrowExcept = true) = 0;
	};

	template<typename TServiceType>
	inline std::shared_ptr<TServiceType> IServiceProvider::GetService()
	{
		decltype(auto) service = GetService(typeid(TServiceType));
		return std::shared_ptr<TServiceType>(service,static_cast<TServiceType*>(service.get()));
	}

	template<typename TServiceType>
	inline std::shared_ptr<TServiceType> IServiceProvider::GetService(nullptr_t)
	{
		decltype(auto) service = GetService(typeid(TServiceType),false);
		return std::shared_ptr<TServiceType>(service, static_cast<TServiceType*>(service.get()));
	}

	template<>
	inline std::shared_ptr<IServiceProvider> IServiceProvider::GetService()
	{
		return shared_from_this();
	}

	template<typename ObjectType>
	inline std::shared_ptr<ObjectType> IServiceProvider::FillObject()
	{
		return std::shared_ptr<ObjectType>(typename ObjectType::CreateSelf(this));
	}
}