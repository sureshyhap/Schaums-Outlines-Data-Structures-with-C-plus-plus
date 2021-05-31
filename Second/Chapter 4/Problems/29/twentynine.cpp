#include <iostream>

long c(int n, int k);

long c(int n, int k) {
  if (k == 0 or k == n) {
    return 1;
  }
  return c(n - 1, k - 1) + c(n - 1, k);
}

int main(int argc, char* argv[]) {
  // n from 0 to 32 with k as half of n
  std::cout << c(32, 16) << '\n';
  return 0;
}
