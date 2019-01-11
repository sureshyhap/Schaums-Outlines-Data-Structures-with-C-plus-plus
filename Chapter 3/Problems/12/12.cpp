#include <iostream>
#include "Line.h"
#include "Point.h"
#define PI 3.14159265359

int main(int argc, char* argv[]) {
  Line l(1, 2, 3);
  Point p(5, 2);
  std::cout << l.contains(p) << std::endl;
  return 0;
}
