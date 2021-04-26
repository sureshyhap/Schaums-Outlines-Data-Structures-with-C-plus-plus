#include <iostream>
#include "../Point.h"

int main(int argc, char* argv[]) {
  Point p(4.5, 1.3);
  Point q(p);
  Point r;
  r = q;
  return 0;
}
