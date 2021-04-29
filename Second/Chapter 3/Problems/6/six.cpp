#include <iostream>
#include "../Point.h"

int main(int argc, char* argv[]) {
  Point p(5, -2);
  std::cout << (p * p).to_string() << '\n';
  std::cout << (p / p).to_string() << '\n';
  return 0;
}
