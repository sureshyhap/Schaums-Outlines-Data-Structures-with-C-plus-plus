#include <iostream>
#include "../Point.h"
#include <cmath>

int main(int argc, char* argv[]) {
  Point p(3.0, 4.0);
  std::cout << p.magnitude() << '\n';
  Point q(2.0, 2.0);
  std::cout << q.amplitude() * 180 / M_PI << '\n';
  return 0;
}
