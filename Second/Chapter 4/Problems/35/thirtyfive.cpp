#include <iostream>

double polynomial(int a[], int size, int n, double x);

// a0 + a1 * x + a2 * x^2 + ... + an * x ^ n ==
// a0 + x(a1 + x(a2 + ... + x(an)))
double polynomial(int a[], int size, int n, double x) {
  if (n == size - 1) {
    return a[n];
  }
  return a[n] + x * polynomial(a, size, n + 1, x);
}

int main(int argc, char* argv[]) {
  int coeff[] = {1, -6, 2, 4};
  std::cout << polynomial(coeff, 4, 0, 2.5) << '\n';
  return 0;
}
