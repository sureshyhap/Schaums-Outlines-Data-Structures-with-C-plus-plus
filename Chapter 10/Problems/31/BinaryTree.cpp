template <typename T>
BinaryTree<T>::BinaryTree(Node* n) : root(n) {
}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree& bt) {
  clone(bt.root, nullptr);
}

template <typename T>
BinaryTree<T>::BinaryTree(const T& r_data) {
  root = new Node(r_data);
}

template <typename T>
BinaryTree<T>::BinaryTree(const T& r_data, const BinaryTree& bt_left, const BinaryTree& bt_right) {
  root = new Node(r_data);
  root->left_child = clone(bt_left.root, root);
  root->right_child = clone(bt_right.root, root);
}

template <typename T>
BinaryTree<T>::BinaryTree(const T& r_data, const BinaryTree& bt, bool is_left) {
  root = new Node(r_data);
  if (is_left) {
    root->left_child = clone(bt.root, root);
  }
  else {
    root->right_child = clone(bt.root, root);
  }
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
  destroy(root);
}

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree& bt) {
  clear();
  BinaryTree* new_tree = new BinaryTree(bt);
  root = new_tree.root;
  return *this;
}

template <typename T>
void BinaryTree<T>::clear() {
  destroy(root);
}

template <typename T>
typename BinaryTree<T>::Iterator BinaryTree<T>::begin() {
  return Iterator(this, root);
}

template <typename T>
typename BinaryTree<T>::Iterator BinaryTree<T>::end() {
  return Iterator(this, nullptr);
}

template <typename T>
bool BinaryTree<T>::empty() const {
  return root == nullptr ? true : false;
}

template <typename T>
int BinaryTree<T>::size(){
  int size = 0;
  for (Iterator it = begin(); it != end(); ++it) {
    ++size;
  }
  return size;
}

template <typename T>
int BinaryTree<T>::leaves() {
  int leaves = 0;
  for (Iterator it = begin(); it != end(); ++it) {
    if (it.p->left_child == nullptr && it.p->right_child == nullptr) {
      ++leaves;
    }
  }
  return leaves;
}

template <typename T>
int BinaryTree<T>::height() {
  int height = 0;
  for (Iterator it = begin(); it != end(); ++it) {
    int depth = 0;
    Node* temp = it.p;
    while (temp != root) {
      ++depth;
      temp = temp->parent;
    }
    if (depth > height) {
      height = depth;
    }
  }
  return height;
}

template <typename T>
int BinaryTree<T>::level(Iterator it) {
  Node* temp = it.p;
  int depth = 0;
  while (temp != root) {
    ++depth;
    temp = temp->parent;
  }
  return depth;
}

template <typename T>
void BinaryTree<T>::reflect() {
  for (Iterator it = begin(); it != end(); ++it) {
    Node* temp = it.p->left_child;
    it.p->left_child = it.p->right_child;
    it.p->right_child = temp;
  }
}

template <typename T>
BinaryTree<T>::Iterator::Iterator(BinaryTree* t, Node* n) : tree(t), p(n) {
}

template <typename T>
BinaryTree<T>::Iterator::Iterator(const Iterator& it) {
  tree = it.tree;
  p = it.p;
}

template <typename T>
typename BinaryTree<T>::Iterator& BinaryTree<T>::Iterator::operator=(const Iterator& it) {
  tree = it.tree;
  p = it.p;  
}

template <typename T>
bool BinaryTree<T>::Iterator::operator==(const Iterator& it) {
  return it.tree == tree && it.p == p;
}

template <typename T>
bool BinaryTree<T>::Iterator::operator!=(const Iterator& it) {
  return it.tree != tree || it.p != p;
}

template <typename T>
typename BinaryTree<T>::Iterator& BinaryTree<T>::Iterator::operator++() {
  this->p = tree->preorder_successor(this->p);
  return *this;
}

template <typename T>
typename BinaryTree<T>::Iterator BinaryTree<T>::Iterator::operator++(int) {
  Iterator temp(*this);
  ++(*this);
  return temp;
}

template <typename T>
T& BinaryTree<T>::Iterator::operator*() const {
  return p->data;
}

template <typename T>
bool BinaryTree<T>::Iterator::operator!() {
  if (p == nullptr) {
    return true;
  }
  else {
    return false;
  }
}

template <typename T>
void BinaryTree<T>::destroy(Node* n) {
  if (n == nullptr) {
    return;
  }
  destroy(n->left_child);
  destroy(n->right_child);
  delete n;
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::preorder_successor(Node* n) {
  if (n->left_child != nullptr) {
    return n->left_child;
  }
  else if (n->right_child != nullptr) {
    return n->right_child;
  }
  // Keep moving up while you are not the root and you are the right child or if there is no right child
  while (n != n->parent && (n == n->parent->right_child || n->parent->right_child == nullptr)) {
    n = n->parent;
  }
  // If reached root at this stage, there is no preorder successor
  if (n == n->parent) {
    return nullptr;
  }
  // n is now a left child with a sibling
  return n->parent->right_child;
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::clone(Node* p, Node* parent) {
  if (p == nullptr) {
    return nullptr;
  }
  Node* r = new Node(p->data, parent);
  r->left_child = clone(p->left_child, r);
  r->right_child = clone(p->right_child, r);
  return r;
}

template <typename T>
BinaryTree<T>::Node::Node(const T& data, Node* parent, Node* left, Node* right) {
  this->data = data;
  this->parent = (parent == nullptr ? this : parent);
  left_child= left;
  right_child = right;
}
