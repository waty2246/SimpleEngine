#pragma once

#include "except.h"
#include <memory>

namespace sp
{
#if defined(NDEBUG)
    template<typename T>
    using scoped_ptr = std::unique_ptr<T>;
#else
    template<typename T>
    struct scoped_deleter
    {
        scoped_deleter()
        {
            TrackingPtr = std::make_shared<size_t>();
        }

        template<typename TOther>
        scoped_deleter(const scoped_deleter<TOther>&) :scoped_deleter<T>()
        {
        }

        void operator()(T* ptr)
        {
            delete ptr;
        }

        std::shared_ptr<size_t> TrackingPtr;
    };

    template<typename T>
    struct scoped_deleter<T[]>
    {
        scoped_deleter()
        {
            TrackingPtr = std::make_shared<size_t>();
        }

        void operator()(T* ptr)
        {
            delete[] ptr;
        }

        std::shared_ptr<size_t> TrackingPtr;
    };

    template<typename T>
    using scoped_ptr = std::unique_ptr<T, scoped_deleter<T>>;
#endif
    template <class _Ty, class... _Types, std::enable_if_t<!std::is_array_v<_Ty>, int> = 0>
    scoped_ptr<_Ty> make_scoped(_Types&&... _Args)
    {
        return scoped_ptr<_Ty>(new _Ty(std::forward<_Types>(_Args)...));
    }

    template <class _Ty, std::enable_if_t<std::is_array_v<_Ty>&& std::extent_v<_Ty> == 0, int> = 0>
    scoped_ptr<_Ty> make_scoped(const size_t _Size)
    {
        using _Elem = std::remove_extent_t<_Ty>;
        return scoped_ptr<_Ty>(new _Elem[_Size]());
    }

    template <class _Ty, class... _Types, std::enable_if_t<std::extent_v<_Ty> != 0, int> = 0>
    void make_scoped(_Types&&...) = delete;
}