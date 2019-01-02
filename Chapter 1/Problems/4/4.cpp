#include <iostream>

int main(int argc, char* argv[]) {
  std::cout << "Input a musical note (letter): ";
  char note;
  std::cin >> note;
  switch (note) {
  case 'C':
    std::cout << "do" << std::endl;
    break;
  case 'D':
    std::cout << "re" << std::endl;
    break;
  case 'E':
    std::cout << "mi" << std::endl;
    break;
  case 'F':
    std::cout << "fa" << std::endl;
    break;
  case 'G':
    std::cout << "so" << std::endl;
    break;
  case 'A':
    std::cout << "la" << std::endl;
    break;
  case 'B':
    std::cout << "ti" << std::endl;
    break;
  default:
    std::cout << "Not a note." << std::endl;
  }
  
  return 0;
}
