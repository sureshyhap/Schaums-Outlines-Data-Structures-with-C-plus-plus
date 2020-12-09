#include <iostream>
#include <cmath>

bool is_prime(int num);

int main(int argc, char* argv[]) {
  int num = {};
  std::cout << "Test primality of a number: ";
  std::cin >> num;
  std::cout << std::boolalpha << is_prime(num) << '\n';
  return 0;
}

bool is_prime(int num) {
  if (num < 2) {
    return false;
  }
  if (num == 2) {
    return true;
  }
  if (num % 2 == 0) {
    return false;
  }
  for (int i = 3; i <= sqrt(num); i += 2) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}
