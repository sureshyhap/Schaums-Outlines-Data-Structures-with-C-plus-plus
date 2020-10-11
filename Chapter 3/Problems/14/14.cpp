#include <iostream>
#include "Line.h"
#include "Point.h"
#define PI 3.14159265359

int main(int argc, char* argv[]) {
  Line l(1, 2, 3), l2(2, 3, 4);
  std::cout << angle(l ,l2) << std::endl;
  return 0;
}
