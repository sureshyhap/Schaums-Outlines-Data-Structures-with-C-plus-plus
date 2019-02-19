#include <iostream>
#include "Polynomial.h"

int main(int argc, char* argv[]) {
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
  Polynomial p6(-p3 + p2);
  p5.print();
  p6.print();
  Polynomial p7(p5 - p6);
  p7.print();
  Polynomial p8(p6 * p7);
  p8.print();
  p6 *= p7;
  p6.print();
  Polynomial p9(8, -1);
  std::cout << antiderivative(p9.get_polynomial().front()) << std::endl;
  derivative(p6).print();
  return 0;
}
