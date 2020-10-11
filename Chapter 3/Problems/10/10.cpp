#include <iostream>
#include "Line.h"
#include "Point.h"
#define PI 3.14159265359

int main(int argc, char* argv[]) {
  Line l(0, 2, 3), l2(2, 0, 3);
  std::cout << l.is_horizontal() << ' ' << l2.is_vertical() << std::endl;
  return 0;
}
