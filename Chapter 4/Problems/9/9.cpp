#include <iostream>
#include <string>

bool palindrome(int first, int last, std::string s);

int main(int argc, char* argv[]) {
  std::string s = "bacab";
  std::cout << palindrome(0, s.length() - 1, s);
  return 0;
}

bool palindrome(int first, int last, std::string s) {
  // == means a single letter which is a palindrome and > means that
  // first and last have crossed which means that it is a palindrome
  if (first >= last) {
    return true;
  }
  // Check first and last letters of substring
  if (s[first] != s[last]) {
    return false;
  }
  // Reduce the problem
  return palindrome(first + 1, last - 1, s);
}
