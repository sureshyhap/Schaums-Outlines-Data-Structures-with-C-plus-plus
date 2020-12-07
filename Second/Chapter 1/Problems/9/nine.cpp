#include <iostream>

int main(int argc, char* argv[]) {
  int rows = {};
  do {
    std::cout << "Enter number of rows (an odd number): ";
    std::cin >> rows;
  } while (rows % 2 == 0);
  for (int i = 0; i <= rows / 2; ++i) {
    for (int j = 0; j < i; ++j) {
      std::cout << ' ';
    }
    std::cout << '*';
    // Subtract 2 for 2 stars and i * 2 for spaces
    for (int j = 0; j < rows - 2 - (i * 2); ++j) {
      std::cout << ' ';
    }
    if (i != rows / 2) {
      std::cout << '*';
    }
    std::cout << '\n';
  }

  for (int i = rows / 2 - 1; i >= 0; --i) {
    for (int j = 0; j < i; ++j) {
      std::cout << ' ';
    }
    std::cout << '*';
    for (int j = 0; j < rows - 2 - (i * 2); ++j) {
      std::cout << ' ';
    }
    std::cout << '*';
    std::cout << '\n';
  }

  return 0;
}
