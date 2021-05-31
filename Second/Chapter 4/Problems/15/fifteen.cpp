#include <iostream>

int fib(int n);

int fib(int n) {
  if (n < 2) {
    return n;
  }
  int f0 = 0, f1 = 1;
  int f2 = {};
  for (int i = 2; i <= n; ++i) {
    f2 = f0 + f1;
    f0 = f1;
    f1 = f2;
  }
  return f2;
}

int main(int argc, char* argv[]) {
  std::cout << fib(8) << '\n';
  return 0;
}
