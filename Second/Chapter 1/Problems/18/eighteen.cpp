#include <iostream>

int sum_digits(int num);

int main(int argc, char* argv[]) {
  std::cout << sum_digits(49205) << '\n';
  return 0;
}

int sum_digits(int num) {
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}
