#include <iostream>
#include "../Point.h"
#include "../Line.h"

int main(int argc, char* argv[]) {
  Line line(1, -1, 0);
  Point p(2, 2);
  std::cout << line.distance_to(p) << '\n';
  Line line2(1, 0, -10);
  Point p2(2, 7);
  std::cout << line2.distance_to(p2) << '\n';
  return 0;
}
