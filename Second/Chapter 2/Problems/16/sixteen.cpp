#include <iostream>
#include <cctype>
#include <string>

int* freqs(const std::string& s);

int main(int argc, char* argv[]) {
  std::string s = "Hello World";
  int* p = freqs(s);
  for (int i = 0; i < 26; ++i) {
    std::cout << char(int('A') + i) << ": " << p[i] << '\n';
  }
  return 0;

}

int* freqs(const std::string& s) {
  int* p = new int[26];
  for (auto elem : s) {
    ++p[tolower(elem) - 'a'];
  }
  return p;
}
