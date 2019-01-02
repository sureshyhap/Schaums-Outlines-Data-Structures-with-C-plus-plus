#include <iostream>

int main(int argc, char* argv[]) {
  std::cout << "Enter an odd positive integer (number of rows): ";
  int rows = 0;
  std::cin >> rows;
  // The maximum length turns out to be the same as the number of rows
  // for this design
  int max_length = rows;
  for (int i = 0; i < rows / 2; ++i) {
    int stars = 1 + (2 * i);
    for (int spaces = (max_length - stars) / 2; spaces > 0; --spaces) {
      std::cout << " ";
    }
    for (int j = 0; j < stars; ++j) {
      std::cout << "*";
    }
    std::cout << std::endl;
  }
  for (int i = 0; i < max_length; ++i) {
    std::cout << "*";
  }
  std::cout << std::endl;
  for (int i = (rows / 2) - 1; i >= 0; --i) {
    int stars = 1 + (2 * i);
    for (int spaces = (max_length - stars) / 2; spaces > 0; --spaces) {
      std::cout << " ";
    }
    for (int j = 0; j < stars; ++j) {
      std::cout << "*";
    }
    // Omits the last endline
    if (i != 0) {
      std::cout << std::endl;
    }
  }  
  
  return 0;
}
