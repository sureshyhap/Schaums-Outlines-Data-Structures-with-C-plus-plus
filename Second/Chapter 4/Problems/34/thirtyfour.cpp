#include <iostream>

double tangent(double x);

double tangent(double x) {
  if (x > -.005 and x < .005) {
    return x + (1 / 3) * (x * x * x);
  }
  return (2 * tangent(x / 2)) / (1 - (tangent(x / 2) * tangent(x / 2)));
}

int main(int argc, char* argv[]) {
  std::cout << tangent(5) << '\n';
  return 0;
}
