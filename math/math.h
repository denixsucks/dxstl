#pragma once

#include <core.h>

namespace math
{
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
__constexpr float PI = 3.14159265358979323846f;
__constexpr float E = 2.71828182845904523536f;
__constexpr float SQRT_2 = 1.41421356237309504880f;
__constexpr float SQRT_3 = 1.73205080756887729352f;
__constexpr float EPSILON = 0.0001f;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template <typename T, typename I> __forceinline T lerp(T x, T y, I t)
{
  return x + (y - x) * t;
}

// ---------------------------------------------------------------------------
template <typename T> __forceinline T max(T x, T y)
{
  return (x > y) ? x : y;
}

// ---------------------------------------------------------------------------
template <typename T> __forceinline T min(T x, T y)
{
  return (x < y) ? x : y;
}

// ---------------------------------------------------------------------------
template <typename T> __forceinline int floor (T x)
{
  return x - (x - (T)(int) x);
}

// ---------------------------------------------------------------------------
template <typename T> __forceinline bool isNan(T x)
{
  uint32 v = bitCast<uint32>(x);
	uint32 exp = (v >> 23) & 0xFF;
	uint32 f = v & 0x7FFFFF;
	return (exp == 0xFF) & (f != 0);
}

}