#include "Stack.h"

template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& s) {
  for (int i = s.size; i > 0; --i) {
    os << s.data[i - 1] << '\n';
  }
  return os;
}

template <typename T>
Stack<T>::Stack() : data(new T[DEFAULT_CAP]), size(0), capacity(DEFAULT_CAP) {
  
}

template <typename T>
Stack<T>::Stack(const Stack<T>& s) : data(new T[s.capacity]), size(s.size), capacity(s.capacity) {
  for (int i = 0; i < size; ++i) {
    data[i] = s.data[i];
  }
}

template <typename T>
Stack<T>::~Stack() {
  delete [] data;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& s) {
  delete [] data;
  data = new T[s.capacity];
  size = s.size;
  capacity = s.capacity;
  for (int i = 0; i < size; ++i) {
    data[i] = s.data[i];
  }
  return *this;
}

template <typename T>
int Stack<T>::get_size() const {
  return size;
}

template <typename T>
bool Stack<T>::is_empty() const {
  return !size;
}

template <typename T>
T& Stack<T>::top() {
  if (is_empty()) {
    // Meaningless data if stack is empty
    T* p = new T;
    return *p;
  }
  return data[size - 1];
}

template <typename T>
void Stack<T>::push(const T& element) {
  if (size == capacity) {
    capacity *= 2;
    T* temp = new T[capacity];
    for (int i = 0; i < size; ++i) {
      temp[i] = data[i];
    }
    delete [] data;
    data = temp;
  }
  data[size++] = element;
}

template <typename T>
void Stack<T>::pop() {
  --size;
}

template <typename T>
void Stack<T>::print() const {
  std::cout << *this << '\n';
}

template <typename T>
T& Stack<T>::bottom() {
  if (is_empty()) {
    // Meaningless data if stack is empty
    T* p = new T;
    return *p;
  }
  return data[0];
}

template class Stack<int>;
template class Stack<char>;

template <typename T>
void reverse(Stack<T>& s) {
  T* temp = new T[s.capacity];
  for (int i = 0; i < s.size; ++i) {
    temp[i] = s.data[s.size - 1 - i];
  }
  delete [] s.data;
  s.data = temp;
}

template void reverse<int>(Stack<int>& s);
