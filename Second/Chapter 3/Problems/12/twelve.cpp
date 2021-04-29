#include <iostream>
#include "../Point.h"
#include "../Line.h"

int main(int argc, char* argv[]) {
  Line l(1, -1, 0);
  Point p(2, 2);
  std::cout << std::boolalpha << l.contains(p) << '\n';
  return 0;
}
