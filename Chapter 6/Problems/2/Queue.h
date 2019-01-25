#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {
 public:
  Queue();
  Queue(const Queue& q);
  ~Queue();
  Queue& operator=(const Queue& q);
  int size_() const;
  bool empty() const;
  T& front_();
  T& back_();
  void push(const T& t);
  void pop();
  void print() const;
 protected:
  class Node {
    friend class Queue;
  public:
    Node(const T& t, Node* n = NULL);
  protected:
    T data;
    Node* next;
  };
  Node* front, *back;
  int size;
};

template <typename T>
void reverse(Queue<T>& q);

#include "Queue.cpp"

#endif // QUEUE_H
