#include <iostream>
#include <vector>

/*
bool isPalindrome(std::string s) {
  Stack<char> stack1, stack2, stack3;
  for (int i = 0; i < s.length(); ++i) {
    stack1.push(s[i]);
    stack2.push(s[i]);
  }
  while (stack2.empty() == false) {
    stack3.push(stack2.top());
    stack2.pop();
  }
  return stack1 == stack3;
}

template <typename T>
void reverse(Stack<T>& s) {
  Stack<T> t;
  while (s.empty() == false) {
    t.push(s.top());
    s.pop();
  }
  s = t;
}
*/

template <typename T>
Stack<T>::Stack() : data() {
  
}

template <typename T>
Stack<T>::Stack(const Stack& s) : data(s.data)  {

}

template <typename T>
Stack<T>::~Stack() {
  data.clear();
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& s) {
  data = s.data;
  return *this;
}

template <typename T>
int Stack<T>::size() const {
  return data.size();
}

template <typename T>
bool Stack<T>::empty() const {
  return data.size() == 0;
}

template <typename T>
T& Stack<T>::top() {
  return data[data.size() - 1];
}

template <typename T>
void Stack<T>::push(const T& t) {
  data.push_back(t);
}

template <typename T>
void Stack<T>::pop() {
  data.pop_back();
}

template <typename T>
void Stack<T>::print() const {
  // Bottom is on the left and top is on the right
  for (int i = 0; i < data.size(); ++i) {
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;
}

/*
template <typename T>
T& Stack<T>::bottom() {
  Node* temp = _top;
  while (temp->_next != NULL) {
    temp = temp->_next;
  }
  return temp->_data;
}

template <typename T>
bool Stack<T>::operator==(const Stack<T>& s2) {
  if (_size != s2._size) {
    return false;
  }
  Stack<T> s_temp = *this;
  Stack<T> s2_temp = s2;
  while (s_temp.empty() == false) {
    if (s_temp.top() != s2_temp.top()) {
      return false;
    }
    s_temp.pop();
    s2_temp.pop();
  }
  return true;
}

template <typename T>
void Stack<T>::clear() {
  // If empty already return
  if (_size == 0) {
    return;
  }
  // Destroy stack from first to last
  while (_top != NULL) {
    Node* temp = _top;
    _top = _top->_next;
    delete temp;
  }
  _size = 0;  
}

template <typename T>
void Stack<T>::popBottom() {
  if (_size == 0) {
    return;
  }
  if (_size == 1) {
    delete _top;
    _top = NULL;
    --_size;
    return;
  }
  Node* temp = _top;
  while (temp->_next->_next != NULL) {
    temp = temp->_next;
  }
  delete temp->_next;
  temp->_next = NULL;
  return;
}

template <typename T>
bool Stack<T>::operator+=(const Stack& s) {
  Stack<T> t(s);
  while (t.empty() == false) {
    push(t.top());
    t.pop();
  }
}

*/
