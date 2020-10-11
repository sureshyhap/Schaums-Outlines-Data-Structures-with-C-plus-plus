#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
 public:
  Stack();
  Stack(const Stack& s);
  ~Stack();
  Stack& operator=(const Stack& s);
  int size() const;
  bool empty() const;
  T& top();
  void push(const T& t);
  void pop();
  void print() const;
  T& bottom();
 protected:
  class Node {
  public:
  Node(const T& data, Node* next = 0) : _data(data), _next(next) {}
    T _data;
    Node* _next;
  };
  Node* _top;
  int _size;
};

template <typename T>
void reverse(Stack<T>& s);

#include "Stack.cpp"

#endif // STACK_H


