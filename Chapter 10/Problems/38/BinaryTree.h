#ifndef BINARYTREE_H
#define BINARYTREE_H

template <typename T>
class BinaryTree {
  class Node;
 public:
  class Iterator;
  BinaryTree(Node* n = nullptr);
  BinaryTree(const BinaryTree& bt);
  BinaryTree(const T& r_data);
  BinaryTree(const T& r_data, const BinaryTree& bt_left, const BinaryTree& bt_right);
  BinaryTree(const T& r_data, const BinaryTree& bt, bool is_left);
  ~BinaryTree();
  BinaryTree& operator=(const BinaryTree& bt);
  void clear();
  Iterator begin();
  Iterator end();
  bool empty() const;
  int size();
  int leaves();
  int height();
  int level(Iterator it);
  void reflect();
  void defoliate();
  T& root_();
  static bool is_root(Iterator it);
  static bool is_leaf(Iterator it);
  static Iterator parent_(Iterator it);
  static Iterator left_child_(Iterator it);
  static Iterator right_child_(Iterator it);
  class Iterator {
  public:
    friend class BinaryTree;
    BinaryTree* tree;
    Node* p;
    Iterator(BinaryTree* t = nullptr, Node* n = nullptr);
    Iterator(const Iterator& it);
    Iterator& operator=(const Iterator& it);
    bool operator==(const Iterator& it);
    bool operator!=(const Iterator& it);
    Iterator& operator++();
    Iterator operator++(int);
    T& operator*() const;
    bool operator!();
  };
  friend class Iterator;
 protected:
  Node* root;
  void destroy(Node* n);
  Node* preorder_successor(Node* n);
  Node* clone(Node* p, Node* parent);
};

template <typename T>
class BinaryTree<T>::Node {
 public:
  Node(const T& data = T(), Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr);
  T data;
  Node* parent, * left_child, * right_child;
};

#include "BinaryTree.cpp"

#endif // BINARYTREE_H
