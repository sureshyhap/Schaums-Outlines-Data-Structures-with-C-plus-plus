#include <iostream>

long fib(int n);

long fib(int n) {
  if (n < 2) {
    return n;
  }
  return fib(n - 1) + fib(n - 2);
}

int main(int argc, char* argv[]) {
  // n from 0 to 46
  std::cout << fib(46) << '\n';
  return 0;
}
