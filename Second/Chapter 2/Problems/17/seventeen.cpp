#include <iostream>

double horner(int coefficients[], int degree, double x);

int main(int argc, char* argv[]) {
  int coefficients[] = {5, -8, 0, 4};
  int size = sizeof(coefficients) / sizeof(int);
  std::cout << horner(coefficients, size - 1, 5) << '\n';
  return 0;
}

// coefficients are the coefficients on each term
// in ascending degree order
double horner(int coefficients[], int degree, double x) {
  double result = coefficients[degree];
  for (int i = degree; i > 0; --i) {
    //    result += ((result * x) + coefficients[i - 1]);
    result = (result * x) + coefficients[i - 1];
  }
  return result;
}
