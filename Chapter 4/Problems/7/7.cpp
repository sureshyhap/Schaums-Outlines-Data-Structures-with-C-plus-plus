#include <iostream>

double power(double x, int n);

int main(int argc, char* argv[]) {
  std::cout << power(5.4, 5);
  return 0;
}

double power(double x, int n) {
  if (n == 1) {
    return x;
  }
  return power(x, n / 2) * power(x, n - (n / 2));
}
