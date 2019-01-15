#include <iostream>
#include <string>

std::string binary_rep(int n);

int main(int argc, char* argv[]) {
  std::cout << binary_rep(19);
  return 0;
}

std::string binary_rep(int n) {
  if (n == 0) {
    return "";
  }
  return (binary_rep(n / 2) + std::to_string(n % 2));
}
