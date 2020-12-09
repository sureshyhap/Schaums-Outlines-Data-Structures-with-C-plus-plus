#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
  std::ifstream infile("input.txt");
  std::ofstream outfile("justified.txt");
  std::string line;
  while (std::getline(infile, line)) {
    outfile << std::string(60 - line.size(), ' ') << line << '\n';
  }
  return 0;
}
