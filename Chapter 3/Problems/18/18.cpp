#include <iostream>
#include "Line.h"
#include "Point.h"
#define PI 3.14159265359

int main(int argc, char* argv[]) {
  Line l(1, 2);
  std::cout << l.to_string()   << std::endl;
  return 0;
}
