#include <iostream>
#include "Polynomial.h"

int main(int argc, char* argv[]) {
  // 5x^3
  Polynomial p(-7, 4);
  p.print();
  Polynomial p2(2, 9);
  p2.print();
  Polynomial p3(6, 1);
  Polynomial p4(5, 0);
  Polynomial p5(p + p2 + p3 + p4);
  p5.print();
  std::cout << p5(2.0) << std::endl;
  (-p5).print();
  return 0;
}
