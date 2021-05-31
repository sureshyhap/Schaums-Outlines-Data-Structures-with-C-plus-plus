#include <iostream>

double sinh(double theta);
double cosh(double theta);

double sinh(double theta) {
  if (theta > -.005 and theta < .005) {
    return theta + (theta * theta * theta) / 6;
  }
  return 2 * sinh(theta / 2) * cosh(theta / 2);
}

double cosh(double theta) {
  if (theta > -.005 and theta < .005) {
    return 1 + (theta * theta) / 2;
  }
  return 1 + 2 * (sinh(theta / 2) * sinh(theta / 2));
}

int main(int argc, char* argv[]) {
  std::cout << sinh(5) << '\n';
  return 0;
}
