#include <iostream>

int main(int argc, char* argv[]) {
  int max_stars = {};
  // Max stars must be odd
  do {
    std::cout << "Enter max stars: ";
    std::cin >> max_stars;
  } while (max_stars % 2 == 0);
  for (int i = 0; i < max_stars / 2; ++i) {
    for (int j = 0; j < max_stars / 2 - i; ++j) {
      std::cout << ' ';
    }
    for (int j = 0; j < 2 * i + 1; ++j) {
      std::cout << '*';
    }
    for (int j = 0; j < max_stars / 2 - 1; ++j) {
      std::cout << ' ';
    }
    std::cout << '\n';
  }
  for (int i = 0; i < max_stars; ++i) {
    std::cout << '*';
  }
  std::cout << '\n';
  for (int i = 0; i < max_stars / 2; ++i) {
    for (int j = 0; j < i + 1; ++j) {
      std::cout << ' ';
    }
    for (int j = 0; j < max_stars - ((i + 1) * 2); ++j) {
      std::cout << '*';
    }
    for (int j = 0; j < i + 1; ++j) {
      std::cout << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}
