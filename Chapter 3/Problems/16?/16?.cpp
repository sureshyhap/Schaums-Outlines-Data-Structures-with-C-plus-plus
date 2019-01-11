#include <iostream>
#include "Line.h"
#include "Point.h"
#define PI 3.14159265359

int main(int argc, char* argv[]) {
  Line l(1, 2, 3);
  Point p(2, 3);
  std::cout << p.distance_to(l) << std::endl;
  return 0;
}
