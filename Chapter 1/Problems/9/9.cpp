#include <iostream>

int main(int argc, char* argv[]) {
  std::cout << "Enter an odd positive integer: ";
  int rows = 0;
  std::cin >> rows;
  int max_length = rows;
  for (int i = 0; i < rows / 2; ++i) {
    // For the initial spaces
    int outer_spaces = 0;
    for (; outer_spaces < i; ++outer_spaces) {
      std::cout << " ";
    }
    std::cout << "*";
    // last -2 is for the two stars on a row
    for (int inner_spaces = max_length - (outer_spaces * 2) - 2; inner_spaces > 0; --inner_spaces) {
      std::cout << " ";
    }
    std::cout << "*" << std::endl;

    
  }
  for (int j = 0; j < max_length / 2; ++j) {
    std::cout << " ";
  }
  std::cout << "*\n";

  for (int i = (rows / 2) - 1; i >= 0; --i) {
    // For the initial spaces
    int outer_spaces = 0;
    for (; outer_spaces < i; ++outer_spaces) {
      std::cout << " ";
    }
    std::cout << "*";
    // last -2 is for the two stars on a row
    for (int inner_spaces = max_length - (outer_spaces * 2) - 2; inner_spaces > 0; --inner_spaces) {
      std::cout << " ";
    }
    std::cout << "*" << std::endl;

  }
    return 0;
}
