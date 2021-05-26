#include <iostream>

int x_to_the_n(int x, int n);

int x_to_the_n(int x, int n) {
  if (n == 1) {
    return x;
  }
  if (n % 2 == 0) {
    return x_to_the_n(x, n / 2) * x_to_the_n(x, n / 2);
  }
  else {
    return x * x_to_the_n(x, n / 2) * x_to_the_n(x, n / 2);
  }
}

int main(int argc, char* argv[]) {
  std::cout << x_to_the_n(3, 5) << '\n';
  std::cout << x_to_the_n(2, 6) << '\n';
  return 0;
}
