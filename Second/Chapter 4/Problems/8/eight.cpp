#include <iostream>

int int_bin_log(int x);

int int_bin_log(int x) {
  if (x <= 1) {
    return 0;
  }
  return 1 + int_bin_log(x / 2);
}

int main(int argc, char* argv[]) {
  std::cout << int_bin_log(115) << '\n';
  return 0;
}
