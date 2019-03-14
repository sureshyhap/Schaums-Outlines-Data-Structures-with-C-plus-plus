#ifndef TREE_H
#define TREE_H

#include <list>
#include <algorithm>

template <typename T>
class Tree {
protected:
  void copy(const Tree& t);
  class Node {
  public:
    Node(const T& data = T(), Node* parent = nullptr);
    // Adds a copy of child to the tree
    void add_child_copy(Node* child);
    // Add a copy of the children in children to the tree
    void add_children_copy(std::list<Node*> children);
    T data;
    Node* parent;
    std::list<Node*> children;
  };
  // Nodes stored in preorder traversal order
  typename std::list<Node*> tree;
public:
  Tree();
  Tree(const Tree& t);
  Tree(const T& data);
  Tree(const T& data, std::list<Tree*>& l);
  ~Tree();
  Tree& operator=(const Tree& t);
  void clear();
  void print() const;
  class Iterator {
  public:
    Iterator();
    Iterator(const Iterator& it);
    Iterator(Tree* t, Node* n = nullptr);
    Iterator(Tree* t, typename std::list<Node*>::iterator it);
    Iterator& operator=(const Iterator& it);
    bool operator==(const Iterator& it);
    bool operator!=(const Iterator& it);
    Iterator& operator++();
    Iterator operator++(int);
    T& operator*() const;
    bool operator!();
    // For traversing the tree using children and parent pointers
    Tree* t;
    // For traversing the tree's list of Node* in preorder
    // traversal ordering
    typename std::list<Node*>::iterator it;
  };
  Iterator begin();
  Iterator end();
  void insert(const T& data, Node* parent);
  void insert(const T& data, Iterator it);
  // For now only allow removal of leaf nodes
  bool remove(const T& data);
  bool search(const T& data);
  bool empty() const;
  int size() const;
  int leaves() const;
  int height() const;
  int level(Iterator it) const;
  int path_length() const;
};

#include "Tree.cpp"

#endif // TREE_H
