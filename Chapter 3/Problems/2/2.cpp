#include <iostream>
#include "Point.h"

int main(int argc, char* argv[]) {
  Point p(3, 4);
  std::cout << p.magnitude() << std::endl;
  Point q(5, 5);
  std::cout << q.amplitude() << std::endl;
  return 0;
}
