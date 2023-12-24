#include <iostream>

#include "../core.h"
#include "../math/math.h"
#include "../math/vec.h"

int main()
{
  auto a = vec2<double>(12.4, 12);
  auto b = a;
  std::cout << b.x << " " << b.y << " " << b.sizeOfElement << "\n";
  return 0;
}