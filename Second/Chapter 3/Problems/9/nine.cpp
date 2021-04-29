#include <iostream>
#include "../Line.h"
#include "../Point.h"

int main(int argc, char* argv[]) {
  Line line(Point(0, 1), 2);
  std::cout << line.slope() << ' ' << line.x_intercept() << ' ' << line.y_intercept() << '\n';
  return 0;
}
