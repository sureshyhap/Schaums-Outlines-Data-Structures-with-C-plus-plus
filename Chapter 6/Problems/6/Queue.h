#ifndef QUEUE_H
#define QUEUE_H

#include <list>

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
  bool operator==(const Queue& q);
  void clear();
  bool operator+=(const Queue& q);
 protected:
  std::list<T> data;
};

/*template <typename T>
void reverse(Queue& q);
*/

#include "Queue.cpp"

#endif // QUEUE_H
