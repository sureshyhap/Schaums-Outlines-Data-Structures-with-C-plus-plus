#include <iostream>
#include "../Stack.h"

int main(int argc, char* argv[]) {
  Stack<int> s;
  s.push(4);
  s.push(10);
  s.push(7);
  s.print();
  reverse(s);
  s.print();
  return 0;
}

