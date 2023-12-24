#pragma once

#include <math.h>
#include <simd.h>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template <typename T>
struct vec2
{
  // -------------------------------------------------------------------------
  union {
    struct {T x, T y};
    T array [2];
  }

  // -------------------------------------------------------------------------
  vec2 operator - () const { return {-x , -y}; }

  vec2 operator + (vec2 b) const { return {x + b.x, y + b.y}; }
  vec2 operator - (vec2 b) const { return {x - b.x, y - b.y}; }
  vec2 operator * (vec2 b) const { return {x * b.x, y * b.y}; }
  vec2 operator / (vec2 b) const { return {x / b.x, y * b.y}; }

  vec2 operator + (T b) const { return {x + b, y + b}; }
  vec2 operator - (T b) const { return {x - b, y - b}; }
  vec2 operator * (T b) const { return {x * b, y * b}; }
  vec2 operator / (T b) const { return {x / b, y * b}; }

  // -------------------------------------------------------------------------
};

template <typename T>
struct vec3
{
  union {
    struct {T x, T y, T z};
    T array [3];
  }

  // -------------------------------------------------------------------------

};

template <typename T>
struct vec4
{
  union {
    struct {T x, T y, T z ,T w};
    T array [4];
  }

  // -------------------------------------------------------------------------
};