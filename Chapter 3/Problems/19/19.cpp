#include <iostream>
#include "Card.h"

int main(int argc, char* argv[]) {
  Card c1;
  Card c2(Card::THREE, Card::DIAMOND);
  Card c3(c1);
  std::cout <<  c1.rank() << ' ' << c1.suit() << ' ' << c1.count() << std::endl;
  std::cout << c2 << std::endl;
  std::cout << c2.abbr() << std::endl;
  std::cout << (c1 < c2) << ' ' << (c1 > c2) << ' ' <<  (c1 <= c2) << ' '
	    <<  (c1 >= c2) << ' ' <<  (c1 == c3) << ' ' <<  (c1 != c3) << std::endl;
  return 0;
}
