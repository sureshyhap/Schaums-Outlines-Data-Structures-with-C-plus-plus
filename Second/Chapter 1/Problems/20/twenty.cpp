#include <iostream>
#include <string>

std::string reverse(const std::string& s);

int main(int argc, char* argv[]) {
  std::cout << reverse("COMPUTER") << '\n';
  return 0;
}

std::string reverse(const std::string& s) {
  if (s.length() == 1) {
    return s;
  }
  return s.back() + reverse(s.substr(0, s.length() - 1));
}
