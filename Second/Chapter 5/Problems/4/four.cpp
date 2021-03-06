#include <iostream>
#include "../Stack.h"
#include <string>

bool is_palindrome(const std::string& s);

bool is_palindrome(const std::string& s) {
  Stack<char> st;
  int length = s.length();
  int i = 0;
  for (; i < length / 2; ++i) {
    st.push(s[i]);
  }
  if (length % 2 != 0) {
    ++i;
  }
  for (; i < length; ++i) {
    if (st.top() != s[i]) {
      return false;
    }
    st.pop();
  }
  return true;
}

int main(int argc, char* argv[]) {
  std::string s = "ABCBA", s2 = "ABCCBA", s3 = "ABCDE";
  std::cout << std::boolalpha << s << ' ' << is_palindrome(s) << '\n';
  std::cout << s2 << ' ' << is_palindrome(s2) << '\n';
  std::cout << s3 << ' ' << is_palindrome(s3) << '\n';
  return 0;
}
