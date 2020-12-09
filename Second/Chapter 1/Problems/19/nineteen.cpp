#include <iostream>
#include <cmath>

int reverse(int num);

int main(int argc, char* argv[]) {
  std::cout << reverse(49205) << '\n';
  return 0;
}

int reverse(int num) {
  int reversed = 0;
  int digit = {};
  int count = log10(num);
  while (num > 0) {
    digit = num % 10;
    reversed += digit * pow(10, count--);
    num /= 10;
  }
  return reversed;
}
