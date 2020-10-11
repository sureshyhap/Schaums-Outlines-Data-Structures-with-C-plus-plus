#include <iostream>
#include "BinarySearchTree.h"
#include <string>

template <typename T>
void sort(T* a, int size);

int main(int argc, char* argv[]) {
  BinarySearchTree<std::string> t;
  t.insert("oats");
  t.insert("corn");
  t.insert("peas");
  t.insert("tuna");
  t.insert("beer");
  t.insert("pork");
  t.insert("eggs");
  t.insert("wine");
  t.print();
  std::cout << std::endl;
  std::cout << t.search("okra") << std::endl;
  t.insert("okra");
  std::cout << t.search("okra") << std::endl;
  int a[] = {5, 3, 4, 6, 8, 7, 9, 1};
  int size = sizeof(a) / sizeof(int);
  sort(a, size);
  for (int i = 0; i < size; ++i) {
    std::cout << a[i] << " ";
  }
  return 0;
}

// O(n log n)
template <typename T>
void sort(T* a, int size) {
  BinarySearchTree<T> bst;
  for (int i = 0; i < size; ++i) {
    bst.insert(a[i]);
  }
  int i = 0;
  bst.in_order(a, i);
}

