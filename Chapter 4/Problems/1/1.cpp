#include <iostream>

int sum_squares(int n);

int main(int argc, char* argv[]) {
  std::cout << sum_squares(5);
  
  return 0;
}

int sum_squares(int n) {
  if (n == 0) {
    return 0;
  }
  return n * n + sum_squares(n - 1);
}
