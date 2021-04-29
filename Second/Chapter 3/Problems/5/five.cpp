#include <iostream>
#include "../Point.h"

int main(int argc, char* argv[]) {
  Point p(5, -2);
  Point q(p);
  Point r(p + q);
  Point s(p - q);
  std::cout << r.to_string() << '\n';
  std::cout << s.to_string() << '\n';
  return 0;
}
