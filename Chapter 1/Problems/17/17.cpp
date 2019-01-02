#include <iostream>
#include <cmath>

bool is_prime(int num);

int main(int argc, char* argv[]) {
  std::cout << "Enter a number: ";
  int num;
  std::cin >> num;
  std::cout << num << " is " << (is_prime(num) ? "a" : "not a") << " prime number.";
  return 0;
}

bool is_prime(int num) {
  // 0 and 1 are not prime
  if (num <= 1) {
    return false;
  }
  // 2 is a prime
  if (num == 2) {
    return true;
  }
  // Even numbers other than 2 are not prime
  else if (num % 2 == 0) {
    return false;
  }
  // If a number ends in 5 it is not prime
  if (num != 5 && num % 10 == 5) {
    return false;
  }
  // Will only have to check factors up to the square root
  // because it is cyclical
  double sqrt_num = sqrt(num);
  for (int i = 3; i <= sqrt_num; i += 2) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}
