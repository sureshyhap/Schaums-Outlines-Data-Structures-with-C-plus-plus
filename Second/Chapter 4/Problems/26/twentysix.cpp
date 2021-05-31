#include <iostream>

long f(int n);

long f(int n) {
  if (n < 2) {
    return 1;
  }
  return n * f(n - 1);
}

int main(int argc, char* argv[]) {
  // 0 to 25
  std::cout << f(25) << '\n';
  return 0;
}
