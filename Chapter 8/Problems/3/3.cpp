#include <iostream>
#include <fstream>
#include "Frequency_Table.h"

int main(int argc, char* argv[]) {
  Frequency_Table ft;
  std::cout << "Enter a filename: ";
  std::string s;
  std::cin >> s;
  std::ifstream infile(s);
  infile >> ft;
  std::cout << ft << '\n';
  return 0;
}
