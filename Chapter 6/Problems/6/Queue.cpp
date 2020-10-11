#include <iostream>
#include <stack>

template <typename T>
Queue<T>::Queue() {
  data;
}

template <typename T>
Queue<T>::Queue(const Queue<T>& q) : data(q.data) {
  
}

template <typename T>
Queue<T>::~Queue() {
  //  data.~list();
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& q) {
  data = q.data;
  return *this;
}

template <typename T>
int Queue<T>::size_() const {
  return data.size();
}

template <typename T>
bool Queue<T>::empty() const {
  return data.empty();
}

template <typename T>
T& Queue<T>::front_() {
  return data.front();
}

template <typename T>
T& Queue<T>::back_() {
  return data.back();
}

template <typename T>
void Queue<T>::push(const T& t) {
  data.push_back(t);
}

template <typename T>
void Queue<T>::pop() {
  data.pop_front();
}

template <typename T>
void Queue<T>::print() const {
  for (auto it = data.begin(); it != data.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

template <typename T>
bool Queue<T>::operator==(const Queue& q) {
  return data == q.data;
}

template <typename T>
void Queue<T>::clear() {
  data.clear();
}

template <typename T>
bool Queue<T>::operator+=(const Queue& q) {
  for (auto it = q.data.begin(); it != q.data.end(); ++it) {
    data.push_back(*it);
  }
  return true;
}

/*
template <typename T>
void reverse(Queue<T>& q) {
  q.data.reverse();
}
*/
