#include <iostream>
#include <fstream>
#include <iomanip>

int main(int argc, char* argv[]) {
  std::ifstream infile("EE Companies.txt");
  std::ofstream outfile("EE Companies Right.txt");
  std::string s;
  while (getline(infile, s)) {
    outfile << std::setw(5) << s;
  }
  return 0;
}
