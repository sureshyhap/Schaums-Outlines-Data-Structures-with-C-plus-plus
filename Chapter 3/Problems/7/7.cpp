#include <iostream>
#include "Point.h"
#define PI 3.14159265359

int main(int argc, char* argv[]) {
  Point p(3, -1), q(5, 2);
  std::cout << distance(p, q) << std::endl;
  return 0;
}
