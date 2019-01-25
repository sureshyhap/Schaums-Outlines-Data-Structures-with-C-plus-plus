#include <iostream>
#include <stack>

template <typename T>
Queue<T>::Queue() : front(NULL), back(NULL), size(0) {

}

template <typename T>
Queue<T>::Queue(const Queue<T>& q) : size(q.size) {
  if (q.empty() == true) {
    front = NULL;
    back = NULL;
    return;
  }
  front = back = new Node(q.front->data);
  Node* p = q.front->next;
  while (p != NULL) {
    back->next = new Node(p->data);
    back = back->next;
    p = p->next;
  }
}

template <typename T>
Queue<T>::~Queue() {
  Node* temp = front;
  while (front != NULL) {
    front = front->next;
    delete temp;
    temp = front;
  }
  size = 0;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& q) {
  Node* temp = front;
  while (front != NULL) {
    front = front->next;
    delete temp;
    temp = front;
  }
  size = q.size;
  if (q.empty() == true) {
    front = NULL;
    back = NULL;
    return *this;
  }
  front = back = new Node(q.front->data);
  Node* p = q.front->next;
  while (p != NULL) {
    back->next = new Node(p->data);
    back = back->next;
    p = p->next;
  }
  return *this;
}

template <typename T>
int Queue<T>::size_() const {
  return size;
}

template <typename T>
bool Queue<T>::empty() const {
  return size == 0;
}

template <typename T>
T& Queue<T>::front_() {
  return front->data;
}

template <typename T>
T& Queue<T>::back_() {
  return back->data;
}

template <typename T>
void Queue<T>::push(const T& t) {
  if (empty()) {
    front = back = new Node(t);
    ++size;
    return;
  }
  back->next = new Node(t);
  back = back->next;
  ++size;
}

template <typename T>
void Queue<T>::pop() {
  if (empty()) {
    return;
  }
  Node* temp = front;
  front = front->next;
  delete temp;
  --size;
}

template <typename T>
void Queue<T>::print() const {
  Node* temp = front;
  while (temp != NULL) {
    std::cout << temp->data << " ";
    temp = temp->next;
  }
  std::cout << std::endl;
}

template <typename T>
bool Queue<T>::operator==(const Queue& q) {
  if (size != q.size) {
    return false;
  }
  Node* temp1 = front;
  Node* temp2 = q.front;
  while (temp1 != NULL) {
    if (temp1->data != temp2->data) {
      return false;
    }
    temp1 = temp1->next;
    temp2 = temp2->next;
  }
  return true;
}

template <typename T>
void Queue<T>::clear() {
  Node* temp = front;
  while (front != NULL) {
    front = front->next;
    delete temp;
    temp = front;
  }
  size = 0;
  front = NULL;
  back = NULL;
}

template <typename T>
bool Queue<T>::operator+=(const Queue& q) {
  Queue<T> q2 = q;
  while (q2.empty() == false) {
    push(q2.front->data);
    q2.pop();
  }
  return true;
}

template <typename T>
Queue<T>::Node::Node(const T& t, Node* n) : data(t), next(n) {
  
}

template <typename T>
void reverse(Queue<T>& q) {
  std::stack<T> s;
  while (q.empty() == false) {
    s.push(q.front_());
    q.pop();
  }
  while (s.empty() == false) {
    q.push(s.top());
    s.pop();
  }
}
