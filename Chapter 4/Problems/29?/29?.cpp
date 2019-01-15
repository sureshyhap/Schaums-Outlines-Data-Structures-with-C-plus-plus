#include <iostream>

long c(int n, int k);

int main(int argc, char* argv[]) {
  return 0;
}

long c(int n, int k) {
  if (k == 0 || k == n) {
    return 1;
  }
  return c(n - 1, k - 1) + c(n - 1, k);
}
