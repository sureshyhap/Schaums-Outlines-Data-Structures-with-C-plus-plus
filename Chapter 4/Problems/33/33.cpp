#include <iostream>

double sinh(double x);
double cosh(double x);

int main(int argc, char* argv[]) {
  std::cout << sinh(5);
  return 0;
}

double sinh(double x) {
  if (-.005 < x && x < .005) {
    return x + ((x * x * x) / 6);
  }
  return 2 * sinh(x / 2) * cosh(x / 2);
}

double cosh(double x) {
  if (-.005 < x && x < .005) {
    return 1 + ((x * x) / 2);
  }
  return 1 + 2 * (sinh(x / 2) * sinh(x / 2));
}
