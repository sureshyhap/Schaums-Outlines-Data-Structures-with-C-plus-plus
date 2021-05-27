#include <iostream>
#include <string>

bool is_pal(std::string s, int n);

bool is_pal(std::string s, int n) {
  // n has crossed the middle
  if (n > s.length() / 2) {
    return true;
  }
  // check outer egde characters and inner substring.
  // Inner substring goes from n + 1 to s.length() - (n + 1).
  // This starts from n + 1 and has s.length() - (n + 1) - (n + 1)
  // characters
  return (s[n] == s[s.length() - 1 - n]) and is_pal(s.substr(n + 1, s.length() - (n + 1) - (n + 1)), n + 1);
}

int main(int argc, char* argv[]) {
  std::cout << std::boolalpha << is_pal("ABRARBA", 0) << '\n';
  std::cout << is_pal("ABRAARBA", 0) << '\n';
  std::cout << is_pal("ABRAKADABRA", 0) << '\n';
  return 0;
}
