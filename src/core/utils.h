#pragma once

#include <functional>
#include <typeindex>  
#include <typeinfo>  
#include "core/ref_ptr.h"

namespace sp
{
    class IServiceProvider;
    class IServiceCollection;
    using hash_code_t = size_t;
    using raw_pointer = void*;
    using create_service_fn = std::function<raw_pointer(sp::ref_ptr<IServiceProvider>)>;
    using delete_service_act = std::function<void(raw_pointer)>;
    using service_factory_1_fn = std::function<raw_pointer(IServiceProvider*)>;
    using service_factory_0_fn = std::function<raw_pointer()>;

    inline size_t HashCode(const std::type_index& typeInfo)
    {
        return typeInfo.hash_code();
    }

    inline size_t HashCode(const std::type_info& typeInfo)
    {
        const std::type_index typeIndex(typeInfo);
        return HashCode(typeIndex);
    }

    template<typename Object>
    struct IsInterface
    {
        constexpr IsInterface()
        {
            static_assert(std::is_abstract<Object>(), "Object must be an interface or abstract class!");
        }
    };

    template<typename TServiceType, typename TServiceImplementation>
    struct Implements
    {
        constexpr Implements()
        {
            static_assert(std::is_base_of<TServiceType, TServiceImplementation>(), "TServiceImplementation does not implement TServiceType!");
        }
    };

    template<typename Object>
    struct IsClass
    {
        constexpr IsClass()
        {
            static_assert(std::is_class<Object>(), "Object must be a class");
        }
    };

    class ServiceResolveException : std::exception
    {
    public:
        ServiceResolveException(const std::type_info& serviceTypeInfo, size_t hashCode);

        const std::type_index& GetServiceType() const;
        const std::string& GetExceptionMessage() const;
        const size_t GetHashCode() const;
        const char* what() const throw() override;

    private:
        void CreateExceptionMessage();

    private:
        sp::scoped_ptr<std::type_index> _serviceTypeInfo;
        const size_t _hashCode;
        std::string _exceptionMessage;
    };

    extern std::pair<std::shared_ptr<IServiceProvider>, std::shared_ptr<IServiceCollection>> CreateServiceProvider();
}