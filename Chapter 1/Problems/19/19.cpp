#include <iostream>
#include <cmath>

int reverse(int num);

int main(int argc, char* argv[]) {
  std::cout << "Enter a positive integer: ";
  int num = 0;
  std::cin >> num;
  std::cout << "The reverse is: " << reverse(num);
  return 0;
}

int reverse(int num) {
  int num_digits = int(log10(num)) + 1;
  int a[num_digits] = {0};
  for (int i = 0; i < num_digits; ++i) {
    // Extracts each digit in reverse order
    a[i] = ((num % int(pow(10, i + 1))) / int(pow(10, i)));
  }
  int new_num = 0;
  for (int i = 0; i < num_digits; ++i) {
    // Creates the number from the digits in the array
    new_num += a[i] * int(pow(10, num_digits - 1 - i));
  }
  return new_num;
}
