#include <iostream>
#include "../Line.h"
#include "../Point.h"

int main(int argc, char* argv[]) {
  Line line1(Line::X_AXIS), line2(Line::Y_AXIS), line3(Line::DIAGONAL);
  std::cout << line1.to_string() << '\n';
  std::cout << line2.to_string() << '\n';
  std::cout << line3.to_string() << '\n';
  return 0;
}
