#include <iostream>
#include <iomanip>

int main(int argc, char* argv[]) {
  for (int i = 1; i <= 12; ++i) {
    for (int j = 1; j <= 12; ++j) {
      std::cout << std::setw(5) << i * j << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}
