#include <iostream>
#include "Big_Int.h"

int main(int argc, char* argv[]) {
  Big_Int b_int1("8324990384000000929449020");
  Big_Int b_int2("98739827407279425");
  //  fdfdfdfdff("8324990482739828336728445");
  Big_Int sum(b_int1 + b_int2);
  sum.print();
  Big_Int b1("10000000");
  Big_Int b2("5");
  Big_Int diff1(b1 - b2);
  diff1.print();
  Big_Int bb1("4353666493859853984");
  Big_Int bb2("331434845455");
  Big_Int prod(bb1 * bb2);
  prod.print();
  Big_Int b;
  std::cin >> b;
  b.print();
  Big_Int bb("200000000");
  Big_Int bbb(bb * 2);
  bbb.print();
  // Too big for an int
  int n = b_int1.to_int();
  std::cout << n << "\n";
  return 0;
}
