#include <iostream>

int sum_powers(int b, int n);

int main(int argc, char* argv[]) {
  std::cout << sum_powers(5, 4);
  
  return 0;
}

int sum_powers(int b, int n) {
  if (n == 1) {
    return b;
  }
  int term = 1;
  for (int i = 0; i < n; ++i) {
    term *= b;
  }
  return term + sum_powers(b, n - 1);
}
