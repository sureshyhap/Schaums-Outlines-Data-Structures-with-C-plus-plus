#include <iostream>

int pow_b_sum(int b, int n);

int pow_b_sum(int b, int n) {
  if (n == 0) {
    return 1;
  }
  return 1 + b * pow_b_sum(b, n - 1);
}

int main(int argc, char* argv[]) {
  std::cout << pow_b_sum(2, 4) << '\n';
  return 0;
}
