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

  BinaryTree<char>::Iterator i_temp;

  for (BinaryTree<char>::Iterator it = a.begin(); it != a.end(); ++it) {
    if (*it == 'E') {
      i_temp = it;
    }
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << a.empty() << '\n';
  std::cout << a.size() << '\n';
  std::cout << a.leaves() << '\n';
  std::cout << a.height() << '\n';
  std::cout << a.level(i_temp) << '\n';
  a.reflect();
  for (BinaryTree<char>::Iterator it = a.begin(); it != a.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  a.defoliate();
  for (BinaryTree<char>::Iterator it = a.begin(); it != a.end(); ++it) {
    if (*it == 'A') {
      i_temp = it;
    }
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  a.root_() = 'X';
  for (BinaryTree<char>::Iterator it = a.begin(); it != a.end(); ++it) {
    if (*it == 'B') {
      i_temp = it;
    }
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << BinaryTree<char>::is_root(i_temp) << std::endl;
  std::cout << BinaryTree<char>::is_leaf(i_temp) << std::endl;
  std::cout << *(BinaryTree<char>::parent_(i_temp)) << std::endl;
  std::cout << *(BinaryTree<char>::left_child_(i_temp)) << std::endl;
  return 0;
}
