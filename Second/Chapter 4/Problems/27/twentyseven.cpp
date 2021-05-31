#include <iostream>

int pow_b_sum(int b, int n);

int pow_b_sum(int b, int n) {
  if (n == 0) {
    return 1;
  }
  return 1 + b * pow_b_sum(b, n - 1);
}

int main(int argc, char* argv[]) {
  // n from 0 to 30
  std::cout << pow_b_sum(2, 30)  << '\n';
  return 0;
}
