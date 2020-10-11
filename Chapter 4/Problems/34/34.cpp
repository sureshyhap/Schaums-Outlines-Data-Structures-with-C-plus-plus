#include <iostream>
#define PI 3.14159265359

double tan(double x);

int main(int argc, char* argv[]) {
  std::cout << tan(PI + .1);
  return 0;
}

double tan(double x) {
  if (-.005 < x && x < .005) {
    return x + ((1 / 3) * (x * x * x));
  }
  return (2 * tan(x / 2)) / (1 - (tan(x / 2) * tan(x / 2)));
}
