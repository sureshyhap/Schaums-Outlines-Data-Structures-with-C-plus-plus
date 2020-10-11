#include <iostream>
#include "Stack.h"

int main(int argc, char* argv[]) {
  Stack<int> s;
  s.push(5);
  s.push(1);
  s.push(1);
  s.push(4);
  s.print();
  s.pop();
  s.pop();
  s.print();
  return 0;
}
