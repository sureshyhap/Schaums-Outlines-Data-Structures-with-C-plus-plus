#include <iostream>

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

template <typename T>
Stack<T>::Stack() : _top(NULL), _size(0) {

}

template <typename T>
Stack<T>::Stack(const Stack& s) : _top(NULL), _size(s._size) {
  // Empty stack
  if (s._size == 0) {
    return;
  }
  // Create the first copied node
  _top = new Node(s._top->_data);
  for (Node* p = _top, *q = s._top->_next; q != NULL; ) {
    // Create copied nodes one by one
    p->_next = new Node(q->_data);
    // Advance the pointers for both stacks
    p = p->_next;
    q = q->_next;
  }
}

template <typename T>
Stack<T>::~Stack() {
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
Stack<T>& Stack<T>::operator=(const Stack& s) {
  // Destroy original stack
  // Destroy stack from first to last
  while (_top != NULL) {
    Node* temp = _top;
    _top = _top->_next;
    delete temp;
  }
  // Create the first copied node
  _top = new Node(s._top->_data);
  for (Node* p = _top, *q = s._top->_next; q != NULL; ) {
    // Create copied nodes one by one
    p->_next = new Node(q->_data);
    // Advance the pointers for both stacks
    p = p->_next;
    q = q->_next;
  }
  _size = s._size;
  return *this;
}

template <typename T>
int Stack<T>::size() const {
  return _size;
}

template <typename T>
bool Stack<T>::empty() const {
  return _size == 0;
}

template <typename T>
T& Stack<T>::top() {
  ///////////////////////// What about if empty
  return _top->_data;
}

template <typename T>
void Stack<T>::push(const T& t) {
  // Create a new node that points to the
  // old first node and _top now points
  // to it
  _top = new Node(t, _top);
  ++_size;
}

template <typename T>
void Stack<T>::pop() {
  if (_size == 0) {
    return;
  }
  Node* temp = _top;
  // top points to potentially
  // the second element
  _top = _top->_next;
  // Delete the first element
  delete temp;
  --_size;
}

template <typename T>
void Stack<T>::print() const {
  if (_size == 0) {
    return;
  }
  for (Node* temp = _top; temp != NULL; temp = temp->_next) {
    std::cout << temp->_data << " ";
  }
  std::cout << std::endl;
}

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
