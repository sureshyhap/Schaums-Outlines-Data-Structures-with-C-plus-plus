#ifndef STACK_H
#define STACK_H
#include <iostream>

template <typename T>
class Stack {
  template <typename T2>
    friend void reverse(Stack<T2>& s);
  template <typename T2>
    friend std::ostream& operator<<(std::ostream& os, const Stack<T2>& s);
 public:
  Stack();
  Stack(const Stack<T>& s);
  ~Stack();
  Stack& operator=(const Stack<T>& s);
  int get_size() const;
  bool is_empty() const;
  T& top();
  void push(const T& element);
  void pop();
  void print() const;
  T& bottom();
 private:
  T* data;
  int size, capacity;
  static const int DEFAULT_CAP = 4;
};

#endif // STACK_H
