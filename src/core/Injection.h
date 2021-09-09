#pragma once

#include "core/ServiceEntry.h"
#include "core/IServiceProvider.h"

#define INJECT(Constructor) \
private: static decltype(auto) CreateSelf(sp::IServiceProvider* serviceProvider)\
{\
    return sp::ObjectFactory<Constructor,sp::FuncInfo<Constructor>::arg_count>::Create(serviceProvider);\
}\
friend class sp::ServiceEntry;\
friend class sp::IServiceProvider;\
public: Constructor

namespace sp
{
    template<typename TFunc>
    struct FuncInfo
    {
    };

    template<typename TResult, typename ... TArgs>
    struct FuncInfo<TResult(TArgs...)>
    {
        static const size_t arg_count = sizeof...(TArgs);
        typedef TResult result_type;
    };

    template<size_t i,typename TResult>
    struct FuncArgExpansion
    {
    };

    template<size_t i, typename TResult, typename ... TArgs>
    struct FuncArgExpansion<i, TResult(TArgs...)>
    {
        typedef typename std::tuple_element<i, std::tuple<TArgs...>>::type type;
    };

    template<typename TConstructor,size_t ArgumentCount>
    struct ObjectFactory
    {
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor,0>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            return new typename FuncInfo<TConstructor>::result_type();
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor,1>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0,TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 2>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1,p2);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 3>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2,p3);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 4>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3,p4);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 5>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4,p5);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 6>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5,p6);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 7>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6,p7);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 8>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7,p8);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 9>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8,p9);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 10>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            auto p10 = serviceProvider->GetService<FuncArgExpansion<9, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8, p9,p10);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 11>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            auto p10 = serviceProvider->GetService<FuncArgExpansion<9, TConstructor>::type::element_type>();
            auto p11 = serviceProvider->GetService<FuncArgExpansion<10, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 12>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            auto p10 = serviceProvider->GetService<FuncArgExpansion<9, TConstructor>::type::element_type>();
            auto p11 = serviceProvider->GetService<FuncArgExpansion<10, TConstructor>::type::element_type>();
            auto p12 = serviceProvider->GetService<FuncArgExpansion<11, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 13>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            auto p10 = serviceProvider->GetService<FuncArgExpansion<9, TConstructor>::type::element_type>();
            auto p11 = serviceProvider->GetService<FuncArgExpansion<10, TConstructor>::type::element_type>();
            auto p12 = serviceProvider->GetService<FuncArgExpansion<11, TConstructor>::type::element_type>();
            auto p13 = serviceProvider->GetService<FuncArgExpansion<12, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 14>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            auto p10 = serviceProvider->GetService<FuncArgExpansion<9, TConstructor>::type::element_type>();
            auto p11 = serviceProvider->GetService<FuncArgExpansion<10, TConstructor>::type::element_type>();
            auto p12 = serviceProvider->GetService<FuncArgExpansion<11, TConstructor>::type::element_type>();
            auto p13 = serviceProvider->GetService<FuncArgExpansion<12, TConstructor>::type::element_type>();
            auto p14 = serviceProvider->GetService<FuncArgExpansion<13, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 15>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            auto p10 = serviceProvider->GetService<FuncArgExpansion<9, TConstructor>::type::element_type>();
            auto p11 = serviceProvider->GetService<FuncArgExpansion<10, TConstructor>::type::element_type>();
            auto p12 = serviceProvider->GetService<FuncArgExpansion<11, TConstructor>::type::element_type>();
            auto p13 = serviceProvider->GetService<FuncArgExpansion<12, TConstructor>::type::element_type>();
            auto p14 = serviceProvider->GetService<FuncArgExpansion<13, TConstructor>::type::element_type>();
            auto p15 = serviceProvider->GetService<FuncArgExpansion<14, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 16>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            auto p10 = serviceProvider->GetService<FuncArgExpansion<9, TConstructor>::type::element_type>();
            auto p11 = serviceProvider->GetService<FuncArgExpansion<10, TConstructor>::type::element_type>();
            auto p12 = serviceProvider->GetService<FuncArgExpansion<11, TConstructor>::type::element_type>();
            auto p13 = serviceProvider->GetService<FuncArgExpansion<12, TConstructor>::type::element_type>();
            auto p14 = serviceProvider->GetService<FuncArgExpansion<13, TConstructor>::type::element_type>();
            auto p15 = serviceProvider->GetService<FuncArgExpansion<14, TConstructor>::type::element_type>();
            auto p16 = serviceProvider->GetService<FuncArgExpansion<15, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 17>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            auto p10 = serviceProvider->GetService<FuncArgExpansion<9, TConstructor>::type::element_type>();
            auto p11 = serviceProvider->GetService<FuncArgExpansion<10, TConstructor>::type::element_type>();
            auto p12 = serviceProvider->GetService<FuncArgExpansion<11, TConstructor>::type::element_type>();
            auto p13 = serviceProvider->GetService<FuncArgExpansion<12, TConstructor>::type::element_type>();
            auto p14 = serviceProvider->GetService<FuncArgExpansion<13, TConstructor>::type::element_type>();
            auto p15 = serviceProvider->GetService<FuncArgExpansion<14, TConstructor>::type::element_type>();
            auto p16 = serviceProvider->GetService<FuncArgExpansion<15, TConstructor>::type::element_type>();
            auto p17 = serviceProvider->GetService<FuncArgExpansion<16, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 18>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            auto p10 = serviceProvider->GetService<FuncArgExpansion<9, TConstructor>::type::element_type>();
            auto p11 = serviceProvider->GetService<FuncArgExpansion<10, TConstructor>::type::element_type>();
            auto p12 = serviceProvider->GetService<FuncArgExpansion<11, TConstructor>::type::element_type>();
            auto p13 = serviceProvider->GetService<FuncArgExpansion<12, TConstructor>::type::element_type>();
            auto p14 = serviceProvider->GetService<FuncArgExpansion<13, TConstructor>::type::element_type>();
            auto p15 = serviceProvider->GetService<FuncArgExpansion<14, TConstructor>::type::element_type>();
            auto p16 = serviceProvider->GetService<FuncArgExpansion<15, TConstructor>::type::element_type>();
            auto p17 = serviceProvider->GetService<FuncArgExpansion<16, TConstructor>::type::element_type>();
            auto p18 = serviceProvider->GetService<FuncArgExpansion<17, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 19>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            auto p10 = serviceProvider->GetService<FuncArgExpansion<9, TConstructor>::type::element_type>();
            auto p11 = serviceProvider->GetService<FuncArgExpansion<10, TConstructor>::type::element_type>();
            auto p12 = serviceProvider->GetService<FuncArgExpansion<11, TConstructor>::type::element_type>();
            auto p13 = serviceProvider->GetService<FuncArgExpansion<12, TConstructor>::type::element_type>();
            auto p14 = serviceProvider->GetService<FuncArgExpansion<13, TConstructor>::type::element_type>();
            auto p15 = serviceProvider->GetService<FuncArgExpansion<14, TConstructor>::type::element_type>();
            auto p16 = serviceProvider->GetService<FuncArgExpansion<15, TConstructor>::type::element_type>();
            auto p17 = serviceProvider->GetService<FuncArgExpansion<16, TConstructor>::type::element_type>();
            auto p18 = serviceProvider->GetService<FuncArgExpansion<17, TConstructor>::type::element_type>();
            auto p19 = serviceProvider->GetService<FuncArgExpansion<18, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 20>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            auto p10 = serviceProvider->GetService<FuncArgExpansion<9, TConstructor>::type::element_type>();
            auto p11 = serviceProvider->GetService<FuncArgExpansion<10, TConstructor>::type::element_type>();
            auto p12 = serviceProvider->GetService<FuncArgExpansion<11, TConstructor>::type::element_type>();
            auto p13 = serviceProvider->GetService<FuncArgExpansion<12, TConstructor>::type::element_type>();
            auto p14 = serviceProvider->GetService<FuncArgExpansion<13, TConstructor>::type::element_type>();
            auto p15 = serviceProvider->GetService<FuncArgExpansion<14, TConstructor>::type::element_type>();
            auto p16 = serviceProvider->GetService<FuncArgExpansion<15, TConstructor>::type::element_type>();
            auto p17 = serviceProvider->GetService<FuncArgExpansion<16, TConstructor>::type::element_type>();
            auto p18 = serviceProvider->GetService<FuncArgExpansion<17, TConstructor>::type::element_type>();
            auto p19 = serviceProvider->GetService<FuncArgExpansion<18, TConstructor>::type::element_type>();
            auto p20 = serviceProvider->GetService<FuncArgExpansion<19, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 21>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            auto p10 = serviceProvider->GetService<FuncArgExpansion<9, TConstructor>::type::element_type>();
            auto p11 = serviceProvider->GetService<FuncArgExpansion<10, TConstructor>::type::element_type>();
            auto p12 = serviceProvider->GetService<FuncArgExpansion<11, TConstructor>::type::element_type>();
            auto p13 = serviceProvider->GetService<FuncArgExpansion<12, TConstructor>::type::element_type>();
            auto p14 = serviceProvider->GetService<FuncArgExpansion<13, TConstructor>::type::element_type>();
            auto p15 = serviceProvider->GetService<FuncArgExpansion<14, TConstructor>::type::element_type>();
            auto p16 = serviceProvider->GetService<FuncArgExpansion<15, TConstructor>::type::element_type>();
            auto p17 = serviceProvider->GetService<FuncArgExpansion<16, TConstructor>::type::element_type>();
            auto p18 = serviceProvider->GetService<FuncArgExpansion<17, TConstructor>::type::element_type>();
            auto p19 = serviceProvider->GetService<FuncArgExpansion<18, TConstructor>::type::element_type>();
            auto p20 = serviceProvider->GetService<FuncArgExpansion<19, TConstructor>::type::element_type>();
            auto p21 = serviceProvider->GetService<FuncArgExpansion<20, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 22>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            auto p10 = serviceProvider->GetService<FuncArgExpansion<9, TConstructor>::type::element_type>();
            auto p11 = serviceProvider->GetService<FuncArgExpansion<10, TConstructor>::type::element_type>();
            auto p12 = serviceProvider->GetService<FuncArgExpansion<11, TConstructor>::type::element_type>();
            auto p13 = serviceProvider->GetService<FuncArgExpansion<12, TConstructor>::type::element_type>();
            auto p14 = serviceProvider->GetService<FuncArgExpansion<13, TConstructor>::type::element_type>();
            auto p15 = serviceProvider->GetService<FuncArgExpansion<14, TConstructor>::type::element_type>();
            auto p16 = serviceProvider->GetService<FuncArgExpansion<15, TConstructor>::type::element_type>();
            auto p17 = serviceProvider->GetService<FuncArgExpansion<16, TConstructor>::type::element_type>();
            auto p18 = serviceProvider->GetService<FuncArgExpansion<17, TConstructor>::type::element_type>();
            auto p19 = serviceProvider->GetService<FuncArgExpansion<18, TConstructor>::type::element_type>();
            auto p20 = serviceProvider->GetService<FuncArgExpansion<19, TConstructor>::type::element_type>();
            auto p21 = serviceProvider->GetService<FuncArgExpansion<20, TConstructor>::type::element_type>();
            auto p22 = serviceProvider->GetService<FuncArgExpansion<21, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 23>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            auto p10 = serviceProvider->GetService<FuncArgExpansion<9, TConstructor>::type::element_type>();
            auto p11 = serviceProvider->GetService<FuncArgExpansion<10, TConstructor>::type::element_type>();
            auto p12 = serviceProvider->GetService<FuncArgExpansion<11, TConstructor>::type::element_type>();
            auto p13 = serviceProvider->GetService<FuncArgExpansion<12, TConstructor>::type::element_type>();
            auto p14 = serviceProvider->GetService<FuncArgExpansion<13, TConstructor>::type::element_type>();
            auto p15 = serviceProvider->GetService<FuncArgExpansion<14, TConstructor>::type::element_type>();
            auto p16 = serviceProvider->GetService<FuncArgExpansion<15, TConstructor>::type::element_type>();
            auto p17 = serviceProvider->GetService<FuncArgExpansion<16, TConstructor>::type::element_type>();
            auto p18 = serviceProvider->GetService<FuncArgExpansion<17, TConstructor>::type::element_type>();
            auto p19 = serviceProvider->GetService<FuncArgExpansion<18, TConstructor>::type::element_type>();
            auto p20 = serviceProvider->GetService<FuncArgExpansion<19, TConstructor>::type::element_type>();
            auto p21 = serviceProvider->GetService<FuncArgExpansion<20, TConstructor>::type::element_type>();
            auto p22 = serviceProvider->GetService<FuncArgExpansion<21, TConstructor>::type::element_type>();
            auto p23 = serviceProvider->GetService<FuncArgExpansion<22, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 24>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            auto p10 = serviceProvider->GetService<FuncArgExpansion<9, TConstructor>::type::element_type>();
            auto p11 = serviceProvider->GetService<FuncArgExpansion<10, TConstructor>::type::element_type>();
            auto p12 = serviceProvider->GetService<FuncArgExpansion<11, TConstructor>::type::element_type>();
            auto p13 = serviceProvider->GetService<FuncArgExpansion<12, TConstructor>::type::element_type>();
            auto p14 = serviceProvider->GetService<FuncArgExpansion<13, TConstructor>::type::element_type>();
            auto p15 = serviceProvider->GetService<FuncArgExpansion<14, TConstructor>::type::element_type>();
            auto p16 = serviceProvider->GetService<FuncArgExpansion<15, TConstructor>::type::element_type>();
            auto p17 = serviceProvider->GetService<FuncArgExpansion<16, TConstructor>::type::element_type>();
            auto p18 = serviceProvider->GetService<FuncArgExpansion<17, TConstructor>::type::element_type>();
            auto p19 = serviceProvider->GetService<FuncArgExpansion<18, TConstructor>::type::element_type>();
            auto p20 = serviceProvider->GetService<FuncArgExpansion<19, TConstructor>::type::element_type>();
            auto p21 = serviceProvider->GetService<FuncArgExpansion<20, TConstructor>::type::element_type>();
            auto p22 = serviceProvider->GetService<FuncArgExpansion<21, TConstructor>::type::element_type>();
            auto p23 = serviceProvider->GetService<FuncArgExpansion<22, TConstructor>::type::element_type>();
            auto p24 = serviceProvider->GetService<FuncArgExpansion<23, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 25>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            auto p10 = serviceProvider->GetService<FuncArgExpansion<9, TConstructor>::type::element_type>();
            auto p11 = serviceProvider->GetService<FuncArgExpansion<10, TConstructor>::type::element_type>();
            auto p12 = serviceProvider->GetService<FuncArgExpansion<11, TConstructor>::type::element_type>();
            auto p13 = serviceProvider->GetService<FuncArgExpansion<12, TConstructor>::type::element_type>();
            auto p14 = serviceProvider->GetService<FuncArgExpansion<13, TConstructor>::type::element_type>();
            auto p15 = serviceProvider->GetService<FuncArgExpansion<14, TConstructor>::type::element_type>();
            auto p16 = serviceProvider->GetService<FuncArgExpansion<15, TConstructor>::type::element_type>();
            auto p17 = serviceProvider->GetService<FuncArgExpansion<16, TConstructor>::type::element_type>();
            auto p18 = serviceProvider->GetService<FuncArgExpansion<17, TConstructor>::type::element_type>();
            auto p19 = serviceProvider->GetService<FuncArgExpansion<18, TConstructor>::type::element_type>();
            auto p20 = serviceProvider->GetService<FuncArgExpansion<19, TConstructor>::type::element_type>();
            auto p21 = serviceProvider->GetService<FuncArgExpansion<20, TConstructor>::type::element_type>();
            auto p22 = serviceProvider->GetService<FuncArgExpansion<21, TConstructor>::type::element_type>();
            auto p23 = serviceProvider->GetService<FuncArgExpansion<22, TConstructor>::type::element_type>();
            auto p24 = serviceProvider->GetService<FuncArgExpansion<23, TConstructor>::type::element_type>();
            auto p25 = serviceProvider->GetService<FuncArgExpansion<24, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 26>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            auto p10 = serviceProvider->GetService<FuncArgExpansion<9, TConstructor>::type::element_type>();
            auto p11 = serviceProvider->GetService<FuncArgExpansion<10, TConstructor>::type::element_type>();
            auto p12 = serviceProvider->GetService<FuncArgExpansion<11, TConstructor>::type::element_type>();
            auto p13 = serviceProvider->GetService<FuncArgExpansion<12, TConstructor>::type::element_type>();
            auto p14 = serviceProvider->GetService<FuncArgExpansion<13, TConstructor>::type::element_type>();
            auto p15 = serviceProvider->GetService<FuncArgExpansion<14, TConstructor>::type::element_type>();
            auto p16 = serviceProvider->GetService<FuncArgExpansion<15, TConstructor>::type::element_type>();
            auto p17 = serviceProvider->GetService<FuncArgExpansion<16, TConstructor>::type::element_type>();
            auto p18 = serviceProvider->GetService<FuncArgExpansion<17, TConstructor>::type::element_type>();
            auto p19 = serviceProvider->GetService<FuncArgExpansion<18, TConstructor>::type::element_type>();
            auto p20 = serviceProvider->GetService<FuncArgExpansion<19, TConstructor>::type::element_type>();
            auto p21 = serviceProvider->GetService<FuncArgExpansion<20, TConstructor>::type::element_type>();
            auto p22 = serviceProvider->GetService<FuncArgExpansion<21, TConstructor>::type::element_type>();
            auto p23 = serviceProvider->GetService<FuncArgExpansion<22, TConstructor>::type::element_type>();
            auto p24 = serviceProvider->GetService<FuncArgExpansion<23, TConstructor>::type::element_type>();
            auto p25 = serviceProvider->GetService<FuncArgExpansion<24, TConstructor>::type::element_type>();
            auto p26 = serviceProvider->GetService<FuncArgExpansion<25, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25, p26);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 27>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            auto p10 = serviceProvider->GetService<FuncArgExpansion<9, TConstructor>::type::element_type>();
            auto p11 = serviceProvider->GetService<FuncArgExpansion<10, TConstructor>::type::element_type>();
            auto p12 = serviceProvider->GetService<FuncArgExpansion<11, TConstructor>::type::element_type>();
            auto p13 = serviceProvider->GetService<FuncArgExpansion<12, TConstructor>::type::element_type>();
            auto p14 = serviceProvider->GetService<FuncArgExpansion<13, TConstructor>::type::element_type>();
            auto p15 = serviceProvider->GetService<FuncArgExpansion<14, TConstructor>::type::element_type>();
            auto p16 = serviceProvider->GetService<FuncArgExpansion<15, TConstructor>::type::element_type>();
            auto p17 = serviceProvider->GetService<FuncArgExpansion<16, TConstructor>::type::element_type>();
            auto p18 = serviceProvider->GetService<FuncArgExpansion<17, TConstructor>::type::element_type>();
            auto p19 = serviceProvider->GetService<FuncArgExpansion<18, TConstructor>::type::element_type>();
            auto p20 = serviceProvider->GetService<FuncArgExpansion<19, TConstructor>::type::element_type>();
            auto p21 = serviceProvider->GetService<FuncArgExpansion<20, TConstructor>::type::element_type>();
            auto p22 = serviceProvider->GetService<FuncArgExpansion<21, TConstructor>::type::element_type>();
            auto p23 = serviceProvider->GetService<FuncArgExpansion<22, TConstructor>::type::element_type>();
            auto p24 = serviceProvider->GetService<FuncArgExpansion<23, TConstructor>::type::element_type>();
            auto p25 = serviceProvider->GetService<FuncArgExpansion<24, TConstructor>::type::element_type>();
            auto p26 = serviceProvider->GetService<FuncArgExpansion<25, TConstructor>::type::element_type>();
            auto p27 = serviceProvider->GetService<FuncArgExpansion<26, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25, p26, p27);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 28>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            auto p10 = serviceProvider->GetService<FuncArgExpansion<9, TConstructor>::type::element_type>();
            auto p11 = serviceProvider->GetService<FuncArgExpansion<10, TConstructor>::type::element_type>();
            auto p12 = serviceProvider->GetService<FuncArgExpansion<11, TConstructor>::type::element_type>();
            auto p13 = serviceProvider->GetService<FuncArgExpansion<12, TConstructor>::type::element_type>();
            auto p14 = serviceProvider->GetService<FuncArgExpansion<13, TConstructor>::type::element_type>();
            auto p15 = serviceProvider->GetService<FuncArgExpansion<14, TConstructor>::type::element_type>();
            auto p16 = serviceProvider->GetService<FuncArgExpansion<15, TConstructor>::type::element_type>();
            auto p17 = serviceProvider->GetService<FuncArgExpansion<16, TConstructor>::type::element_type>();
            auto p18 = serviceProvider->GetService<FuncArgExpansion<17, TConstructor>::type::element_type>();
            auto p19 = serviceProvider->GetService<FuncArgExpansion<18, TConstructor>::type::element_type>();
            auto p20 = serviceProvider->GetService<FuncArgExpansion<19, TConstructor>::type::element_type>();
            auto p21 = serviceProvider->GetService<FuncArgExpansion<20, TConstructor>::type::element_type>();
            auto p22 = serviceProvider->GetService<FuncArgExpansion<21, TConstructor>::type::element_type>();
            auto p23 = serviceProvider->GetService<FuncArgExpansion<22, TConstructor>::type::element_type>();
            auto p24 = serviceProvider->GetService<FuncArgExpansion<23, TConstructor>::type::element_type>();
            auto p25 = serviceProvider->GetService<FuncArgExpansion<24, TConstructor>::type::element_type>();
            auto p26 = serviceProvider->GetService<FuncArgExpansion<25, TConstructor>::type::element_type>();
            auto p27 = serviceProvider->GetService<FuncArgExpansion<26, TConstructor>::type::element_type>();
            auto p28 = serviceProvider->GetService<FuncArgExpansion<27, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25, p26, p27, p28);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 29>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            auto p10 = serviceProvider->GetService<FuncArgExpansion<9, TConstructor>::type::element_type>();
            auto p11 = serviceProvider->GetService<FuncArgExpansion<10, TConstructor>::type::element_type>();
            auto p12 = serviceProvider->GetService<FuncArgExpansion<11, TConstructor>::type::element_type>();
            auto p13 = serviceProvider->GetService<FuncArgExpansion<12, TConstructor>::type::element_type>();
            auto p14 = serviceProvider->GetService<FuncArgExpansion<13, TConstructor>::type::element_type>();
            auto p15 = serviceProvider->GetService<FuncArgExpansion<14, TConstructor>::type::element_type>();
            auto p16 = serviceProvider->GetService<FuncArgExpansion<15, TConstructor>::type::element_type>();
            auto p17 = serviceProvider->GetService<FuncArgExpansion<16, TConstructor>::type::element_type>();
            auto p18 = serviceProvider->GetService<FuncArgExpansion<17, TConstructor>::type::element_type>();
            auto p19 = serviceProvider->GetService<FuncArgExpansion<18, TConstructor>::type::element_type>();
            auto p20 = serviceProvider->GetService<FuncArgExpansion<19, TConstructor>::type::element_type>();
            auto p21 = serviceProvider->GetService<FuncArgExpansion<20, TConstructor>::type::element_type>();
            auto p22 = serviceProvider->GetService<FuncArgExpansion<21, TConstructor>::type::element_type>();
            auto p23 = serviceProvider->GetService<FuncArgExpansion<22, TConstructor>::type::element_type>();
            auto p24 = serviceProvider->GetService<FuncArgExpansion<23, TConstructor>::type::element_type>();
            auto p25 = serviceProvider->GetService<FuncArgExpansion<24, TConstructor>::type::element_type>();
            auto p26 = serviceProvider->GetService<FuncArgExpansion<25, TConstructor>::type::element_type>();
            auto p27 = serviceProvider->GetService<FuncArgExpansion<26, TConstructor>::type::element_type>();
            auto p28 = serviceProvider->GetService<FuncArgExpansion<27, TConstructor>::type::element_type>();
            auto p29 = serviceProvider->GetService<FuncArgExpansion<28, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25, p26, p27, p28, p29);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 30>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            auto p10 = serviceProvider->GetService<FuncArgExpansion<9, TConstructor>::type::element_type>();
            auto p11 = serviceProvider->GetService<FuncArgExpansion<10, TConstructor>::type::element_type>();
            auto p12 = serviceProvider->GetService<FuncArgExpansion<11, TConstructor>::type::element_type>();
            auto p13 = serviceProvider->GetService<FuncArgExpansion<12, TConstructor>::type::element_type>();
            auto p14 = serviceProvider->GetService<FuncArgExpansion<13, TConstructor>::type::element_type>();
            auto p15 = serviceProvider->GetService<FuncArgExpansion<14, TConstructor>::type::element_type>();
            auto p16 = serviceProvider->GetService<FuncArgExpansion<15, TConstructor>::type::element_type>();
            auto p17 = serviceProvider->GetService<FuncArgExpansion<16, TConstructor>::type::element_type>();
            auto p18 = serviceProvider->GetService<FuncArgExpansion<17, TConstructor>::type::element_type>();
            auto p19 = serviceProvider->GetService<FuncArgExpansion<18, TConstructor>::type::element_type>();
            auto p20 = serviceProvider->GetService<FuncArgExpansion<19, TConstructor>::type::element_type>();
            auto p21 = serviceProvider->GetService<FuncArgExpansion<20, TConstructor>::type::element_type>();
            auto p22 = serviceProvider->GetService<FuncArgExpansion<21, TConstructor>::type::element_type>();
            auto p23 = serviceProvider->GetService<FuncArgExpansion<22, TConstructor>::type::element_type>();
            auto p24 = serviceProvider->GetService<FuncArgExpansion<23, TConstructor>::type::element_type>();
            auto p25 = serviceProvider->GetService<FuncArgExpansion<24, TConstructor>::type::element_type>();
            auto p26 = serviceProvider->GetService<FuncArgExpansion<25, TConstructor>::type::element_type>();
            auto p27 = serviceProvider->GetService<FuncArgExpansion<26, TConstructor>::type::element_type>();
            auto p28 = serviceProvider->GetService<FuncArgExpansion<27, TConstructor>::type::element_type>();
            auto p29 = serviceProvider->GetService<FuncArgExpansion<28, TConstructor>::type::element_type>();
            auto p30 = serviceProvider->GetService<FuncArgExpansion<29, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25, p26, p27, p28, p29, p30);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 31>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            auto p10 = serviceProvider->GetService<FuncArgExpansion<9, TConstructor>::type::element_type>();
            auto p11 = serviceProvider->GetService<FuncArgExpansion<10, TConstructor>::type::element_type>();
            auto p12 = serviceProvider->GetService<FuncArgExpansion<11, TConstructor>::type::element_type>();
            auto p13 = serviceProvider->GetService<FuncArgExpansion<12, TConstructor>::type::element_type>();
            auto p14 = serviceProvider->GetService<FuncArgExpansion<13, TConstructor>::type::element_type>();
            auto p15 = serviceProvider->GetService<FuncArgExpansion<14, TConstructor>::type::element_type>();
            auto p16 = serviceProvider->GetService<FuncArgExpansion<15, TConstructor>::type::element_type>();
            auto p17 = serviceProvider->GetService<FuncArgExpansion<16, TConstructor>::type::element_type>();
            auto p18 = serviceProvider->GetService<FuncArgExpansion<17, TConstructor>::type::element_type>();
            auto p19 = serviceProvider->GetService<FuncArgExpansion<18, TConstructor>::type::element_type>();
            auto p20 = serviceProvider->GetService<FuncArgExpansion<19, TConstructor>::type::element_type>();
            auto p21 = serviceProvider->GetService<FuncArgExpansion<20, TConstructor>::type::element_type>();
            auto p22 = serviceProvider->GetService<FuncArgExpansion<21, TConstructor>::type::element_type>();
            auto p23 = serviceProvider->GetService<FuncArgExpansion<22, TConstructor>::type::element_type>();
            auto p24 = serviceProvider->GetService<FuncArgExpansion<23, TConstructor>::type::element_type>();
            auto p25 = serviceProvider->GetService<FuncArgExpansion<24, TConstructor>::type::element_type>();
            auto p26 = serviceProvider->GetService<FuncArgExpansion<25, TConstructor>::type::element_type>();
            auto p27 = serviceProvider->GetService<FuncArgExpansion<26, TConstructor>::type::element_type>();
            auto p28 = serviceProvider->GetService<FuncArgExpansion<27, TConstructor>::type::element_type>();
            auto p29 = serviceProvider->GetService<FuncArgExpansion<28, TConstructor>::type::element_type>();
            auto p30 = serviceProvider->GetService<FuncArgExpansion<29, TConstructor>::type::element_type>();
            auto p31 = serviceProvider->GetService<FuncArgExpansion<30, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25, p26, p27, p28, p29, p30, p31);
        }
    };

    template<typename TConstructor>
    struct ObjectFactory<TConstructor, 32>
    {
        static decltype(auto) Create(sp::IServiceProvider* serviceProvider)
        {
            auto p1 = serviceProvider->GetService<FuncArgExpansion<0, TConstructor>::type::element_type>();
            auto p2 = serviceProvider->GetService<FuncArgExpansion<1, TConstructor>::type::element_type>();
            auto p3 = serviceProvider->GetService<FuncArgExpansion<2, TConstructor>::type::element_type>();
            auto p4 = serviceProvider->GetService<FuncArgExpansion<3, TConstructor>::type::element_type>();
            auto p5 = serviceProvider->GetService<FuncArgExpansion<4, TConstructor>::type::element_type>();
            auto p6 = serviceProvider->GetService<FuncArgExpansion<5, TConstructor>::type::element_type>();
            auto p7 = serviceProvider->GetService<FuncArgExpansion<6, TConstructor>::type::element_type>();
            auto p8 = serviceProvider->GetService<FuncArgExpansion<7, TConstructor>::type::element_type>();
            auto p9 = serviceProvider->GetService<FuncArgExpansion<8, TConstructor>::type::element_type>();
            auto p10 = serviceProvider->GetService<FuncArgExpansion<9, TConstructor>::type::element_type>();
            auto p11 = serviceProvider->GetService<FuncArgExpansion<10, TConstructor>::type::element_type>();
            auto p12 = serviceProvider->GetService<FuncArgExpansion<11, TConstructor>::type::element_type>();
            auto p13 = serviceProvider->GetService<FuncArgExpansion<12, TConstructor>::type::element_type>();
            auto p14 = serviceProvider->GetService<FuncArgExpansion<13, TConstructor>::type::element_type>();
            auto p15 = serviceProvider->GetService<FuncArgExpansion<14, TConstructor>::type::element_type>();
            auto p16 = serviceProvider->GetService<FuncArgExpansion<15, TConstructor>::type::element_type>();
            auto p17 = serviceProvider->GetService<FuncArgExpansion<16, TConstructor>::type::element_type>();
            auto p18 = serviceProvider->GetService<FuncArgExpansion<17, TConstructor>::type::element_type>();
            auto p19 = serviceProvider->GetService<FuncArgExpansion<18, TConstructor>::type::element_type>();
            auto p20 = serviceProvider->GetService<FuncArgExpansion<19, TConstructor>::type::element_type>();
            auto p21 = serviceProvider->GetService<FuncArgExpansion<20, TConstructor>::type::element_type>();
            auto p22 = serviceProvider->GetService<FuncArgExpansion<21, TConstructor>::type::element_type>();
            auto p23 = serviceProvider->GetService<FuncArgExpansion<22, TConstructor>::type::element_type>();
            auto p24 = serviceProvider->GetService<FuncArgExpansion<23, TConstructor>::type::element_type>();
            auto p25 = serviceProvider->GetService<FuncArgExpansion<24, TConstructor>::type::element_type>();
            auto p26 = serviceProvider->GetService<FuncArgExpansion<25, TConstructor>::type::element_type>();
            auto p27 = serviceProvider->GetService<FuncArgExpansion<26, TConstructor>::type::element_type>();
            auto p28 = serviceProvider->GetService<FuncArgExpansion<27, TConstructor>::type::element_type>();
            auto p29 = serviceProvider->GetService<FuncArgExpansion<28, TConstructor>::type::element_type>();
            auto p30 = serviceProvider->GetService<FuncArgExpansion<29, TConstructor>::type::element_type>();
            auto p31 = serviceProvider->GetService<FuncArgExpansion<30, TConstructor>::type::element_type>();
            auto p32 = serviceProvider->GetService<FuncArgExpansion<31, TConstructor>::type::element_type>();
            return new typename FuncInfo<TConstructor>::result_type(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25, p26, p27, p28, p29, p30, p31, p32);
        }
    };
}

