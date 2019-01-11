#include <iostream>
#include "Point.h"
#define PI 3.14159265359

int main(int argc, char* argv[]) {
  Point p(3, -1);
  std::cout << (2 * p).toString() << std::endl;
  std::cout << (p / 2).toString() << std::endl;
  return 0;
}
