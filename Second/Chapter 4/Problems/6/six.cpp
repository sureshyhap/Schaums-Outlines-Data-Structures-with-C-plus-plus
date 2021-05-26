#include <iostream>

int x_to_the_n(int x, int n);

int x_to_the_n(int x, int n) {
  if (n == 0) {
    return 1;
  }
  return x * x_to_the_n(x, n - 1);
}

int main(int argc, char* argv[]) {
  std::cout << x_to_the_n(5, 3) << '\n';
  return 0;
}
