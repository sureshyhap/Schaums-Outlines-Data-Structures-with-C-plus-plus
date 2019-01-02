#include <iostream>

int main(int argc, char* argv[]) {
  std::cout << "Enter a nonnegative integer: ";
  int num = 0;
  std::cin >> num;
  int factorial = 1;
  for (int i = num; i > 0; --i) {
    factorial *= i;
  }
  std::cout << num << "! = " << factorial;
  
  return 0;
}
