#include <iostream>
#include "../Point.h"
#include "../Line.h"

int main(int argc, char* argv[]) {
  Point p(Point::ORIGIN);
  Line l(Line::DIAGONAL);
  std::cout << std::boolalpha << p.is_on(l) << '\n';
  return 0;
}
