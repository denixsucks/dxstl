#pragma once

#include "../core.h"

NAMESPACE
namespace math
{
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
__constexpr float PI = 3.14159265358979323846f;
__constexpr float E = 2.71828182845904523536f;
__constexpr float SQRT_2 = 1.41421356237309504880f;
__constexpr float SQRT_3 = 1.73205080756887729352f;
__constexpr float EPSILON = 0.0001f;

// ---------------------------------------------------------------------------
// https://en.wikipedia.org/wiki/Fast_inverse_square_root
template <typename T> __forceinline T rsqrt(T number)
{
  long i;
  T x2, y;
  const float threehalfs = 1.5F;

  x2 = number * 0.5F;
  y  = number;
  i  = * ( long * ) &y;                       // evil floating point bit level hacking
  i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
  y  = * ( float * ) &i;
  y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
  // y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

  return y;
}


// ---------------------------------------------------------------------------
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
  u32 v = bitCast<u32>(x);
	u32 exp = (v >> 23) & 0xFF;
	u32 f = v & 0x7FFFFF;
	return (exp == 0xFF) & (f != 0);
}

}
END_NAMESPACE
