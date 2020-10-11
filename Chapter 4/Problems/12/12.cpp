#include <iostream>

std::string hex_rep(int n);

int main(int argc, char* argv[]) {
  std::cout << hex_rep(155);
  return 0;
}

std::string hex_rep(int n) {
  if (n == 0) {
    return "0x";
  }
  std::string s = std::to_string(n % 16);
  switch (n % 16) {
  case 10:
    s = "A";
    break;
  case 11:
    s = "B";
    break;
  case 12:
    s = "C";
    break;
  case 13:
    s = "D";
    break;
  case 14:
    s = "E";
    break;
  case 15:
    s = "F";
    break;
  }
  return (hex_rep(n / 16) + s);
}
