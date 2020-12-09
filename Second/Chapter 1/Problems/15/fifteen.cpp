#include <iostream>

int discrete_binary_log(double num);

int main(int argc, char* argv[]) {
  std::cout << discrete_binary_log(500) << '\n';
  return 0;
}

int discrete_binary_log(double num) {
  int count = 0;
  while (num > 1) {
    num /= 2;
    ++count;
  }
  return count;
}
