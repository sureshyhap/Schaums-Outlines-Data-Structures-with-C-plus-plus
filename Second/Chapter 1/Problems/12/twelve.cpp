#include <iostream>

int factorial(int n);

int main(int argc, char* argv[]) {
  std::cout << factorial(5) << '\n';
  return 0;
}

int factorial(int n) {
  int product = 1;
  for (int i = n; i > 0; --i) {
    product *= i;
  }
  return product;
}
