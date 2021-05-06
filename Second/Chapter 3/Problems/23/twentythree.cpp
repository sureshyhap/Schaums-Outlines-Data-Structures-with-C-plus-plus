#include <iostream>
#include "../Purse.h"

int main(int argc, char* argv[]) {
  Purse p(4, 10, 2, 5);
  std::cout << p << '\n';
  p.insert(1.67);
  std::cout << p << '\n';
  bool successful_remove = p.remove(2.43);
  if (successful_remove) {
    std::cout << p << '\n';
  }
  else {
    std::cout << "Could not remove" << '\n';
  }
  successful_remove = p.remove(.75);
  if (successful_remove) {
    std::cout << p << '\n';
  }
  else {
    std::cout << "Could not remove" << '\n';
  }  
  return 0;
}
