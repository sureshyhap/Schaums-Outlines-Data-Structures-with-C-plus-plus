#include <iostream>
#include "Line.h"
#include "Point.h"
#include "RandomLine.h"
#define PI 3.14159265359

int main(int argc, char* argv[]) {
  RandomLine rl;
  std::cout << rl.to_string() << std::endl;
  return 0;
}
