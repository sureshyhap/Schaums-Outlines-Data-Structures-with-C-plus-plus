#include <iostream>

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
