#include <iostream>
#include "Line.h"
#include "Point.h"
#define PI 3.14159265359

int main(int argc, char* argv[]) {
  Line l(1, 0, 3);
  std::cout << l.slope() << ' ' << l.x_intercept() << ' ' << l.y_intercept() << std::endl;
  return 0;
}
