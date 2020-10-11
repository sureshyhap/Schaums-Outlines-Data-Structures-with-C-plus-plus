#include <iostream>

int binary_log(int n);

int main(int argc, char* argv[]) {
  std::cout << binary_log(128);
  return 0;
}

int binary_log(int n) {
  if (n == 1) {
    return 0;
  }
  return 1 + binary_log(n / 2);
}
