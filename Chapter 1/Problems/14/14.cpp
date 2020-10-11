#include <iostream>
#include <cmath>

int main(int argc, char* argv[]) {
  std::cout << "Enter x > 0: ";
  double x = 0;
  std::cin >> x;
  double y = 1;
  if (x >  2) {
    y = x / 2;
  }
  while (fabs((y * y) - x) > .1) {
    y = (y + x / y) / 2;
  }
  std::cout << "sqrt(x) is approximately: " << y << std::endl;
  return 0;
}
