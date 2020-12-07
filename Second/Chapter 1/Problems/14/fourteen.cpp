#include <iostream>
#include <cmath>

double babylonian_sqrt(double x);

int main(int argc, char* argv[]) {
  std::cout << babylonian_sqrt(5.34) << '\n';
  return 0;
}

double babylonian_sqrt(double x) {
  try {
    if (x < 0) {
      throw std::runtime_error("Only works for x > 0");
    }
    else {
      double y = 1;
      if (x > 2) {
	y = x / 2;
      }
      double cutoff = .01;
      while (abs(y * y - x) > cutoff) {
	y = (y + (x / y)) / 2;
      }
      return y;
    }
  }
  catch (const std::runtime_error& re) {
    std::cerr << re.what() << '\n';
    return double();
  }
}
