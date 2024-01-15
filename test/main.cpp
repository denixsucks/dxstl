#include <iostream>

#include "../math/math.h"
#include "../math/vector.h"

int main()
{
  auto test_float_vector = dx::vector::vec2<float>(0,1.6);
  auto test_int_vector = dx::vector::vec2<int>(0,4);
  std::cout << test_float_vector.y << " " << test_int_vector.y << "\n";
  return 0;
}
