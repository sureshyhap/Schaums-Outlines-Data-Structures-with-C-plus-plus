#include <iostream>
#include "../Point.h"
#include "../Line.h"

int main(int argc, char* argv[]) {
  Line line(0, 5, 10);
  std::cout << std::boolalpha << line.is_horizontal() << '\n';
  Line line2(5, 0, 10);
  std::cout << line2.is_vertical() << '\n';
  return 0;
}
