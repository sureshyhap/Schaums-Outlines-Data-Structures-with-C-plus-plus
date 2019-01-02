#include <iostream>
#include <cmath>

int digit_sum(int num);

int main(int argc, char* argv[]) {
  std::cout << digit_sum(49205);
  return 0;
}

int digit_sum(int num) {
  int num_digits = int(log10(num)) + 1;
  int total = 0;
  for (int i = 0; i < num_digits; ++i) {
    // Extracts each digit
    total += ((num % int(pow(10, i + 1))) / int(pow(10, i)));
  }
  return total;
}
