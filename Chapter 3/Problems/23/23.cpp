#include <iostream>
#include "Purse.h"
#include <cmath>

int main(int argc, char* argv[]) {
  Purse p(3.49);
  p.print();
  std::cout << std::endl;
  p.insert(.01);
  p.print();
  std::cout << std::endl;
  p.remove(2.37);
  p.print();
  std::cout << std::endl;
  return 0;
}

