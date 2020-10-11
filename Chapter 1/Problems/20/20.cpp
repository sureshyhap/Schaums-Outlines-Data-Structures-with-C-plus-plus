#include <iostream>
#include <string>

std::string reverse(std::string str);

int main(int argc, char* argv[]) {
  std::cout << "Enter a string: ";
  std::string s;
  std::cin >> s;
  std::cout << "The reverse is: " << reverse(s);
  return 0;
}

std::string reverse(std::string str) {
  std::string str_rev = str;
  int length = str.length();
  for (int i = 0; i < length; ++i) {
    str_rev[i] = str[length - 1 - i];
  }
  return str_rev;
}
