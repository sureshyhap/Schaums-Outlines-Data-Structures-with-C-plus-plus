#include <iostream>
#include <string>

int* tally_letters(std::string s);

int main(int argc, char* argv[]) {
  std::string s = "AJDFNLKFNKLFNFNPNIPKK";
  std::cout << s << std::endl;
  int* p = tally_letters(s);
  int length = s.length();
  for (int i = 0; i < 26; ++i) {
    std::cout << char('A' + i) << ": "
	      << p[i] << std::endl;
  }
  return 0;
}

int* tally_letters(std::string s) {
  int* tally = new int[26];
  for (int i = 0; i < 26; ++i) {
    tally[i] = 0;
  }
  int length = s.length();
  for (int i = 0; i < length; ++i) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      ++tally[int(s[i] - 'A')];
    }
    if (s[i] >= 'a' && s[i] <= 'z') {
      ++tally[int(s[i] - 'a')];
    }
  }
  return tally;
}
