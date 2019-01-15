#include <iostream>

double power(double x, int n);

int main(int argc, char* argv[]) {
  double x = 5.4;
  int n = 5;
  std::cout << power(x, n);
  return 0;
}

double power(double x, int n) {
  if (n == 0) {
    return 1;
  }
  return x * power(x, n - 1);
}
