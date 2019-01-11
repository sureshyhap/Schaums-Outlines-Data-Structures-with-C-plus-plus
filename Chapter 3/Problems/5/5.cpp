#include <iostream>
#include "Point.h"
#define PI 3.14159265359

int main(int argc, char* argv[]) {
  Point p(3, -1), q(-1, 5);
  std::cout << (p + q).toString() << std::endl;
  std::cout << (p - q).toString() << std::endl;
  return 0;
}
