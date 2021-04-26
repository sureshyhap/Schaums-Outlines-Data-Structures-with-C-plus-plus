#include <iostream>
#include "../Point.h"
#include <cmath>

int main(int argc, char* argv[]) {
  Point p(1.0, 1.0);
  std::cout << p.to_string() << ' ' << p.r() << ' ' << p.theta() * 180 / M_PI << '\n';
  p.rotate(M_PI / 2);
  std::cout << p.to_string() << ' ' << p.r() << ' ' << p.theta() * 180 / M_PI << '\n';
  return 0;
}
