#include <iostream>

std::string binary_rep(int x);

std::string binary_rep(int x) {
  if (x == 0) {
    return "";
  }
  if (x % 2 == 1) {
    return binary_rep(x / 2) + "1";
  }
  else {
    return binary_rep(x / 2) + "0";
  }
}

int main(int argc, char* argv[]) {
  std::cout << binary_rep(243) << '\n';
  return 0;
}
