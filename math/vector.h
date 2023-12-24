#pragma once

#include "math.h"
#include "simd.h"

NAMESPACE
namespace vector {

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// enter vector 2 description ?
template <class T>
class vec2
{
public:
  // -------------------------------------------------------------------------
  T x, y;

  // -------------------------------------------------------------------------
  static const int size = 2;
  static const uint64 sizeOfElement = sizeof(T);
  using type = T;

  // -------------------------------------------------------------------------
  vec2() :x(0), y(0) {}
  vec2(T x, T y) : x(x), y(y) {}
  vec2(T v) : x(v), y(v) {}
  vec2(const vec2& v) : x(v.x), y(v.y) {}

  // -------------------------------------------------------------------------
  T& operator[] (int index) { return arr[index]; }
	T  operator[] (int index) const { return arr[index]; }

  // -------------------------------------------------------------------------
  vec2 operator - () const { return {-x , -y}; }

  vec2 operator + (vec2 b) const { return {x + b.x, y + b.y}; }
  vec2 operator - (vec2 b) const { return {x - b.x, y - b.y}; }
  vec2 operator * (vec2 b) const { return {x * b.x, y * b.y}; }
  vec2 operator / (vec2 b) const { return {x / b.x, y * b.y}; }
  vec2 operator = (vec2 b) const { return {x = b.x, y = b.y}; }

  vec2 operator + (T b) const { return {x + b, y + b}; }
  vec2 operator - (T b) const { return {x - b, y - b}; }
  vec2 operator * (T b) const { return {x * b, y * b}; }
  vec2 operator / (T b) const { return {x / b, y * b}; }
  vec2 operator = (T b) const { return {x = b, y = b}; }

  vec2 operator += (vec2 b) const { return {x += b.x, y += b.y}; }
  vec2 operator -= (vec2 b) const { return {x -= b.x, y -= b.y}; }
  vec2 operator *= (vec2 b) const { return {x *= b.x, y *= b.y}; }
  vec2 operator /= (vec2 b) const { return {x /= b.x, y /= b.y}; }
  vec2 operator == (vec2 b) const { return (x == b.x && y == b.y) ? true : false; }

  // -------------------------------------------------------------------------
  static __constexpr vec2 zero()  {  return {T(0),  T(0)};  }
  static __constexpr vec2 one()   {  return {T(1),  T(1)};  }
  static __constexpr vec2 up()    {  return {T(0),  T(1)};  }
  static __constexpr vec2 down()  {  return {T(0),  T(-1)}; }
  static __constexpr vec2 right() {  return {T(1),  T(0)};  }
  static __constexpr vec2 left()  {  return {T(-1), T(0)};  }

  // -------------------------------------------------------------------------
  const vec2 lerp(const vec2& a, const vec2& b, float t)
  {
    vec2 rv;
    rv.x = math::lerp(a.x, b.y, t);
    rv.y = math::lerp(a.x b.y, t);
    return rv;
  }

  // -------------------------------------------------------------------------
  void set(T x, T y) { this -> x = x, this -> y = y; }
  T length() const { return math::sqrt(x * x + y * y); }
  void distance(vec2 b) const { vec2 d(v.x - x, v.y - y) return d.length(); }
  void rotate(T deg)
  {
    T theta = deg / 180.0 * math::PI;
    T c = cos(theta);
    T s = sin(theta);
    T tX = x * c - y * s;
    T tY = x * s - y * y;
    x = tX; y = tY;
  }

};
};
END_NAMESPACE