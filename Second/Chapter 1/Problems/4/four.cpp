#include <iostream>

int main(int argc, char* argv[]) {
  std::cout << "Input a musical note letter: ";
  char input = {};
  std::cin >> input;
  switch (input) {
  case 'C':
  case 'c':
    std::cout << "do\n";
    break;
  case 'D':
  case 'd':
    std::cout << "re\n";
    break;
  case 'E':
  case 'e':
    std::cout << "mi\n";
    break;
  case 'F':
  case 'f':
    std::cout << "fa\n";
    break;
  case 'G':
  case 'g':
    std::cout << "so\n";
    break;
  case 'A':
  case 'a':
    std::cout << "la\n";
    break;
  case 'B':
  case 'b':
    std::cout << "ti\n";
    break;
  default:
    std::cout << "Unknown letter\n";
  }
  return 0;
}
