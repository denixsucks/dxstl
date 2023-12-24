#include <iostream>

#include "../core.h"
#include "../math/math.h"
#include "../math/vector.h"

using namespace dx::math;
using namespace dx::vector;

int main()
{
  auto a = rsqrt(4);
  auto v = vec2(0,1);
  std::cout << a << "\n";
  return 0;
}