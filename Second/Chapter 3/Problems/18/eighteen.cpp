#include <iostream>
#include "../Point.h"
#include "../Line.h"

int main(int argc, char* argv[]) {
  Line line(5, 4);
  std::cout << line.to_string() << '\n';
  return 0;
}
