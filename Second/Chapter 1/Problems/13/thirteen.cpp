#include <iostream>

double e(double x, int terms);

int main(int argc, char* argv[]) {
  std::cout << e(1, 10) << '\n';
  return 0;
}

double e(double x, int terms) {
  double sum = 1;
  double term = 1;
  for (int i = 1; i < terms; ++i) {
    term = term * x / i;
    sum += term;
  }
  return sum;
}

