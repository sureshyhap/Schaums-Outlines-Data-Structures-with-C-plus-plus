#include <iostream>
#include "../Point.h"
#include "../Line.h"
#include <cmath>

int main(int argc, char* argv[]) {
  Line line1(1, 1, 5), line2(-1, 1, 10);
  std::cout << angle(line1, line2) * 180 / M_PI << '\n';
  line1 = std::move(Line(0, 1, 10));
  line2 = std::move(Line(1, 0, 10));
  std::cout << angle(line1, line2) * 180 / M_PI << '\n';
  return 0;
}
