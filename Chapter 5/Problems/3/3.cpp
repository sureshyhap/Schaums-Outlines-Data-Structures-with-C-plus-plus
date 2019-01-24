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
  return 0;
}
