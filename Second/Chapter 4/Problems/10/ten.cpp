#include <iostream>

std::string reverse(std::string s, int n);

std::string reverse(std::string s, int n) {
  static int length = s.length();
  if (n == length - 1) {
    std::string s2 = "";
    return s2 + s[0];
  }
  return s.substr(length - 1 - n, 1) + reverse(s.substr(0, length - 1 - n), n + 1);
}

int main(int argc, char* argv[]) {
  std::cout << reverse("ABCDEFG", 0) << '\n';
  return 0;
}
