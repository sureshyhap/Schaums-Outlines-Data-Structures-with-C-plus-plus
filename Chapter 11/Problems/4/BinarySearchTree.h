#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <typename T>
class BinarySearchTree {
  class Node {
  public:
    Node(const T& data = T(), Node* left = nullptr, Node* right = nullptr);
    T data;
    Node* left_child, * right_child;
  };
 public:
  BinarySearchTree();
  void insert(const T& data);
  void print() const;
  bool search(const T& data) const;
  void in_order(T* a, int& i);
  void sort(T* a, int size);
 protected:
  Node* root;
  void insert(Node*& p, const T& data);
  void print(Node* p) const;
  bool search(Node* p, const T& data) const;
  void in_order(Node* p, T* a, int& i);
};

#include "BinarySearchTree.cpp"

#endif // BINARYSEARCHTREE_h
