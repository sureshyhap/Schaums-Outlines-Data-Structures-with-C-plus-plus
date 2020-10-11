#include <iostream>
#include "Point.h"
#define PI 3.14159265359

int main(int argc, char* argv[]) {
  Point p(3, 0);
  p.rotate(PI / 2);
  std::cout << p.toString() << std::endl;
  return 0;
}
