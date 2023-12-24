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
#elif __CLANG__
  #define __forceinline [[clang::always_inline]] 
#elif __GNUC__
  #ifndef __forceinline
    #define __forceinline inline __attribute__((always_inline))
  #endif
#endif

// ---------------------------------------------------------------------------
#if AX_CPP_VERSION < AX_CPP14
  // below c++ 14 does not support constexpr functions
  #define __constexpr
#else
  #define __constexpr constexpr
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