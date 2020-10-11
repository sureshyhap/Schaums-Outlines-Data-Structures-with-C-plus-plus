template <typename T>
BinarySearchTree<T>::Node::Node(const T& data, Node* left, Node* right) {
  this->data = data;
  left_child = left;
  right_child = right;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr) {
}

template <typename T>
void BinarySearchTree<T>::insert(const T& data) {
  insert(root, data);
}

template <typename T>
void BinarySearchTree<T>::print() const {
  print(root);
}

template <typename T>
bool BinarySearchTree<T>::search(const T& data) const {
  search(root, data);
}

template <typename T>
void BinarySearchTree<T>::in_order(T* a, int& i) {
  in_order(root, a, i);
}

template <typename T>
void BinarySearchTree<T>::insert(Node*& p, const T& data) {
  if (p == nullptr) {
    p = new Node(data);
    return;
  }
  if (data < p->data) {
    insert(p->left_child, data);
  }
  else if (data > p->data) {
    insert(p->right_child, data);
  }
  else {
    return;
  }
}

template <typename T>
void BinarySearchTree<T>::print(Node* p) const {
  if (p == nullptr) {
    return;
  }
  print(p->left_child);
  std::cout << p->data << " ";
  print(p->right_child);
}

template <typename T>
bool BinarySearchTree<T>::search(Node* p, const T& data) const {
  if (p == nullptr) {
    return false;
  }
  if (data == p->data) {
    return true;
  }
  else if (data < p->data) {
    return search(p->left_child, data);
  }
  else if (data > p->data) {
    return search(p->right_child, data);
  }
}

template <typename T>
void BinarySearchTree<T>::in_order(Node* p, T* a, int& i) {
  if (p == nullptr) {
    return;
  }
  in_order(p->left_child, a, i);
  a[i++] = p->data;
  in_order(p->right_child, a, i);
}
