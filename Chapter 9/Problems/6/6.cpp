#include <iostream>
#include "Tree.h"

int main(int argc, char* argv[]) {
  Tree<int> t;
  t.insert(5, nullptr);
  Tree<int>::Iterator it(t.begin());
  t.insert(7, it);
  t.insert(8, it);
  t.insert(9, it);
  ++it;
  ++it;
  t.insert(10, it);
  ++it;
  t.insert(11, it);
  t.print();
  return 0;
}
