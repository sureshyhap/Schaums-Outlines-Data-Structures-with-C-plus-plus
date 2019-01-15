#include <iostream>

long fib(int n);

int main(int argc, char* argv[]) {
  std::cout << fib(45); // Too slow after 45
  return 0;
}

long fib(int n) {
  if (n < 2) {
    return n;
  }
  return fib(n - 1) + fib(n - 2);
}
