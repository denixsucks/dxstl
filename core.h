#ifndef DXSX_CORE
#define DXSX_CORE

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define __STDC_LIMIT_MACROS
#include <stdint.h>
#include <float.h>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;
typedef signed char int8;
typedef signed short int16;
typedef signed int int32;
typedef signed long long int64;
typedef uint8_t  uchar;
typedef uint16_t ushort;
typedef uint32_t uint;
typedef uint64_t ulong;

// ---------------------------------------------------------------------------
#ifdef _MSC_VER
  #define VC_EXTRALEAN 1
  #include <intrin.h>
  #define VECTORCALL __vectorcall
#elif __CLANG__
  #define VECTORCALL [[clang::vectorcall]]
#elif __GNUC__
  #define VECTORCALL
#endif

// ---------------------------------------------------------------------------
#if defined(__clang__) || defined(__GNUC__)
    #define CPP_VERSION __cplusplus
    #define CPP14 201402L
    #define CPP17 201703L
    #define CPP20 202002L
#elif defined(_MSC_VER)
    #define CPP_VERSION _MSC_VER
    #define CPP14 1900
    #define CPP17 1910
    #define CPP20 1920
#endif

#define USE_NAMESPACE
#ifdef USE_NAMESPACE
  #define NAMESPACE namespace dx {
  #define END_NAMESPACE }
#else
  #define NAMESPACE
  #define END_NAMESPACE
#endif

// ---------------------------------------------------------------------------
#ifdef _MSC_VER
#elif __CLANG__
  #define __forceinline [[clang::always_inline]] 
#elif __GNUC__
  #ifndef __forceinline
    #define __forceinline inline __attribute__((always_inline))
  #endif
#endif

// ---------------------------------------------------------------------------
#if CPP_VERSION < CPP14
  // below c++ 14 does not support constexpr functions
  #define __constexpr
#else
  #define __constexpr constexpr
#endif

// ---------------------------------------------------------------------------
// https://nullprogram.com/blog/2022/06/26/
#if defined(_DEBUG) || defined(Debug)
  #if __GNUC__
    #define ASSERT(c) if (!(c)) __builtin_trap()
  #elif _MSC_VER
    #define ASSERT(c) if (!(c)) __debugbreak()
  #else
    #define ASSERT(c) if (!(c)) *(volatile int *)0 = 0
  #endif
#else
  #define ASSERT(c)
#endif

// ---------------------------------------------------------------------------
template <typename T, typename F> __forceinline __constexpr T bitCast(const F& v) 
{
  #if AX_CPP_VERSION < AX_CPP17
    return *(const T*)&v;
  #else
    return *(const T *)&v;
  #endif
}

// ---------------------------------------------------------------------------
template<typename T> __forceinline bool isNull(T o)
{
  return (o == nullptr);
}


#endif