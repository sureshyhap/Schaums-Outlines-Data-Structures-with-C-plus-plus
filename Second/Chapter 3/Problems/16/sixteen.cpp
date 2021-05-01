#include <iostream>
#include "../Point.h"
#include "../Line.h"

int main(int argc, char* argv[]) {
  Point p(1, 1);
  Line l(Line::DIAGONAL);
  std::cout << p.distance_to(l) << '\n';
  return 0;
}
