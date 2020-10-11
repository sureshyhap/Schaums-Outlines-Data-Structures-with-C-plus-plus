#include <iostream>
#include "Tree.h"

int main(int argc, char* argv[]) {
  Tree<int> t, t2(5);
  t.insert(5, nullptr);
  Tree<int>::Iterator it(t.begin()), it2(t2.begin());
  std::cout << (Tree<int>::is_root(it) ? "yes" : "no") << "\n";
  std::cout << t.level(it2) << std::endl;
  t.insert(7, it);
  t.insert(8, it);
  t.insert(9, it);
  ++it;
  ++it;
  t.insert(10, it);
  ++it;
  t.insert(11, it);
  t.print();
  std::cout << t.leaves() << "\n";
  std::cout << t.height() << "\n";
  std::cout << t.level(it) << std::endl;
  std::cout << t.path_length() << std::endl;
  return 0;
}
