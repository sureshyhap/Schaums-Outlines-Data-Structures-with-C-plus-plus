#include <iostream>
#include "BinaryTree.h"

int main(int argc, char* argv[]) {
  BinaryTree<char> h('H');
  BinaryTree<char> i('I');
  BinaryTree<char> d('D', h, i);
  BinaryTree<char> j('J');
  BinaryTree<char> e('E', j, true);
  BinaryTree<char> b('B', d, e);
  BinaryTree<char> m('M');
  BinaryTree<char> f('F', m, false);
  BinaryTree<char> c('C', f, true);
  BinaryTree<char> a('A', b, c);
  
  for (BinaryTree<char>::Iterator it = a.begin(); it != a.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << a.empty() << '\n';
  return 0;
}
