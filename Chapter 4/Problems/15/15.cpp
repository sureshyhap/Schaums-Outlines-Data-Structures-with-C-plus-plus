#include <iostream>

int fib(int n);

int main(int argc, char* argv[]) {
  std::cout << fib(7);
  return 0;
}

int fib(int n) {
  if (n < 2) {
    return 1;
  }
  int n1 = 1, n2 = 1, n3 = n1 + n2;
  for (int i = 2; i < n; ++i) {
    n3 = n1 + n2;
    n1 = n2;
    n2 = n3;
  }
  return n3;
}
