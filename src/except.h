#pragma once

#if !defined(NDEBUG)
#define SP_THROW_IF_FALSE(expression,message) if(!(expression)) __debugbreak()
#define SP_THROW_EXCEPT(message) __debugbreak()
#else
#define SP_THROW_IF_FALSE(expression,message) ThrowIfFalse(expression,#expression ## " : " ## message)
#define SP_THROW_EXCEPT(message) throw std::runtime_error(message)

inline void ThrowIfFalse(bool result, const char* message)
{
    if (!result)
    {
        SP_THROW_EXCEPT(message);
    }
}

#endif