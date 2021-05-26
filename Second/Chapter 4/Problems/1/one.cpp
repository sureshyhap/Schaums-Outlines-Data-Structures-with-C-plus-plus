#include <iostream>

int sum_squares(int n);

int sum_squares(int n) {
  if (n == 1) {
    return 1;
  }
  return (n * n) + sum_squares(n - 1);
}

int main(int argc, char* argv[]) {
  std::cout << sum_squares(4) << '\n';
  return 0;
}
