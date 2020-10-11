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
  std::cout << (Tree<int>::is_leaf(it) ? "yes is leaf" : "no not leaf") << "\n";
  ++it;
  std::cout << (Tree<int>::is_oldest_child(it) ? "oldest child" : "not oldest child") << std::endl;
  ++it;
  Tree<int>::Iterator iter1(it);
  t.insert(10, it);
  ++it;
  std::cout << (Tree<int>::is_leaf(it) ? "yes is leaf" : "no not leaf") << "\n";
  t.insert(11, it);
  ++it;
  Tree<int>::Iterator iter2(it);
  t.print();
  std::cout << t.leaves() << "\n";
  std::cout << t.height() << "\n";
  std::cout << t.level(it) << std::endl;
  std::cout << t.path_length() << std::endl;
  std::cout << t.root() << std::endl;
  std::cout << t.generations(iter2, iter1) << "\n";
  std::cout << t.width(1) << std::endl;
  t.print_level(1);
  std::cout << std::endl;
  t.print_level_all();
  t.reflect();
  t.print_level(1);
  return 0;
}
