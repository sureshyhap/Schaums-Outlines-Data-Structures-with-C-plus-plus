#ifndef STACK_H
#define STACK_H

#include <vector>

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
  /*
  T& bottom();
  bool operator==(const Stack& s2);
  void clear();
  void popBottom();
  bool operator+=(const Stack& s);
  */
 protected:
  std::vector<T> data;
};
/*
template <typename T>
void reverse(Stack<T>& s);

bool isPalindrome(std::string s);
*/

#include "Stack.cpp"

#endif // STACK_H
