#include <iostream>
#include "../Point.h"
#include "../Line.h"

int main(int argc, char* argv[]) {
  Line line(1, 1, 0);
  Line line2(1, 1, 5);
  std::cout << are_parallel(line, line2) << '\n';
  line = std::move(Line(1, 1, 0));
  line2 = std::move(Line(-1, 1, 5));
  std::cout << are_perpendicular(line, line2) << '\n';  
  return 0;
}
