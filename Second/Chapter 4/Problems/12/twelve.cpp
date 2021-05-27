#include <iostream>

std::string binary_rep(int x);

std::string binary_rep(int x) {
  if (x == 0) {
    return "";
  }
  if (x % 16 == 0) {
    return binary_rep(x / 16) + "0";
  }
  else if (x % 16 == 1) {
    return binary_rep(x / 16) + "1";
  }
  else if (x % 16 == 2) {
    return binary_rep(x / 16) + "2";
  }
  else if (x % 16 == 3) {
    return binary_rep(x / 16) + "3";
  }
  else if (x % 16 == 4) {
    return binary_rep(x / 16) + "4";
  }
  else if (x % 16 == 5) {
    return binary_rep(x / 16) + "5";
  }
  else if (x % 16 == 6) {
    return binary_rep(x / 16) + "6";
  }
  else if (x % 16 == 7) {
    return binary_rep(x / 16) + "7";
  }
  else if (x % 16 == 8) {
    return binary_rep(x / 16) + "8";
  }
  else if (x % 16 == 9) {
    return binary_rep(x / 16) + "9";
  }
  else if (x % 16 == 10) {
    return binary_rep(x / 16) + "A";
  }
  else if (x % 16 == 11) {
    return binary_rep(x / 16) + "B";
  }
  else if (x % 16 == 12) {
    return binary_rep(x / 16) + "C";
  }
  else if (x % 16 == 13) {
    return binary_rep(x / 16) + "D";
  }
  else if (x % 16 == 14) {
    return binary_rep(x / 16) + "E";
  }
  else if (x % 16 == 15) {
    return binary_rep(x / 16) + "F";
  }
}

int main(int argc, char* argv[]) {
  std::cout << binary_rep(243) << '\n';
  return 0;
}
