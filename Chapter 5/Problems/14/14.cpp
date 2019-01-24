#include <iostream>
#include "Stack.h"

int main(int argc, char* argv[]) {
  Stack<int> s;
  s.push(5);
  s.push(9);
  s.push(0);
  s.push(4);
  s.print();
  s.pop();
  s.print();
  return 0;
}
