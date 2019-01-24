#include <iostream>
#include "Stack.h"

int main(int argc, char* argv[]) {
  Stack<int> s;
  s.push(5);
  s.push(3);
  s.push(6);
  s.print();
  s.pop();
  s.print();
  Stack<int> t(s);
  t.print();
  Stack<int> u;
  u.push(10);
  u.push(34);
  u.push(12);
  u.print();
  t = u;
  t.print();
  reverse(t);
  t.print();
  std::cout << t.bottom() << std::endl;
  std::string str = "ABCBA";
  std::string str2 = "ABCD";
  std::cout << isPalindrome(str) << std::endl;
  std::cout << isPalindrome(str2) << std::endl;
  return 0;
}
