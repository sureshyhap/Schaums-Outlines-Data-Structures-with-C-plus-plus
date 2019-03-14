template <typename T>
void Tree<T>::copy(const Tree& t) {
  tree = t.tree;
  return;
}

template <typename T>
Tree<T>::Node::Node(const T& data, Node* parent) {
  this->data = data;
  // If root
  if (parent == nullptr) {
    this->parent = this;
  }
  else {
    this->parent = parent;
  }
  children = std::list<Node*>();
}

template <typename T>
void Tree<T>::Node::add_child_copy(Node* child) {
  /*
  // Make a copy of child node
  Node* p = new Node(*child);
  // Add it to the tree
  children.push_back(p);
  return;
  *////////////////////////////////////////////
  
}

template <typename T>
void Tree<T>::Node::add_children_copy(std::list<Node*> children) {
  /*
  for (typename std::list<Node*>::iterator it = children.begin(); it != children.end(); ++it) {
    // Make a copy of child node
    Node* p = new Node(**it);
    // Add it to the tree
    this->children.push_back(p);
  }
  return;
  */////////////////////////////////////////////
}

template <typename T>
Tree<T>::Tree() {
  tree = std::list<Node*>();
}

template <typename T>
Tree<T>::Tree(const Tree& t) {
  copy(t);
}

template <typename T>
Tree<T>::Tree(const T& data) {
  Node* p = new Node(data);
  tree.push_back(p);
}

template <typename T>
Tree<T>::Tree(const T& data, std::list<Tree*>& l) {
  // The root
  Node* p = new Node(data);
  tree.push_back(p);
  for (typename std::list<Tree*>::iterator it = l.begin(); it != l.end(); ++it) {
    // Making the root point to each of the Tree* in l
    p->children.push_back(((*it)->tree).front());
    // Making each of the roots of the Trees in l point to the ultimate root
    (((*it)->tree).front())->parent = p;
    // Adding each subtree to the tree list
    for (typename std::list<Node*>::iterator it_node = ((*it)->tree).begin(); it_node != ((*it)->tree).end(); ++it_node) {
      tree.push_back(*it_node);
    }
  }
}

template <typename T>
Tree<T>::~Tree() {
  for (typename std::list<Node*>::iterator it = tree.begin(); it != tree.end(); ++it) {
    delete *it;
  }
  tree.clear();
}

template <typename T>
Tree<T>& Tree<T>::operator=(const Tree& t) {
  tree.clear();
  copy(t);
}

template <typename T>
void Tree<T>::clear() {
  for (typename std::list<Node*>::iterator it = tree.begin(); it != tree.end(); ++it) {
    delete *it;
  }
  tree.clear();
}

template <typename T>
void Tree<T>::print() const {
  for (typename std::list<Node*>::const_iterator it = tree.begin(); it != tree.end(); ++it) {
    std::cout << (*it)->data << " ";
  }
  std::cout << std::endl;
}

template <typename T>
Tree<T>::Iterator::Iterator() {
  t = nullptr;
  it = typename std::list<Node*>::iterator();
}

template <typename T>
Tree<T>::Iterator::Iterator(const Iterator& it) {
  t = it.t;
  this->it = it.it;
}

template <typename T>
Tree<T>::Iterator::Iterator(Tree* t, Node* n) {
  this->t = t;
  typename std::list<Node*>::iterator it = std::find(t->tree.begin(), t->tree.end(), n);
  // n is not in tree ////////////////////////////
  ////////////////////////////////////
  this->it = it;
}

template <typename T>
Tree<T>::Iterator::Iterator(Tree* t, typename std::list<Node*>::iterator it) {
  this->t = t;
  this->it = it;
}

template <typename T>
typename Tree<T>::Iterator& Tree<T>::Iterator::operator=(const Iterator& it) {
  t = it.t;
  this->it = it.it;
}

template <typename T>
bool Tree<T>::Iterator::operator==(const Iterator& it) {
  return t == it.t && it == it.it;
}

template <typename T>
bool Tree<T>::Iterator::operator!=(const Iterator& it) {
  return t != it.t || it != it.it;
}

// Princrement
template <typename T>
typename Tree<T>::Iterator& Tree<T>::Iterator::operator++() {
  // NEED TO FIX THIS
  /////////////////////////////////  if (it != tree.end()) {
    ++it;
    ///////////////////////////////  }
  return *this;
}

// Postincrement
template <typename T>
typename Tree<T>::Iterator Tree<T>::Iterator::operator++(int) {
  Iterator temp(*this);
  // NEED TO FIX THIS
  /////////////////////////////////  if (it != tree.end()) {
    ++it;
    /////////////////////////////////  }
  return temp;
}

template <typename T>
T& Tree<T>::Iterator::operator*() const {
  if (it != tree.end()) {
    return (*it)->data;
  }
  // But what will this return if the iterator is "null"?
  /////////////////////////////////
}

template <typename T>
bool Tree<T>::Iterator::operator!() {
  return t == nullptr || it == tree.end();
}

template <typename T>
typename Tree<T>::Iterator Tree<T>::begin() {
  typename std::list<Node*>::iterator it = (this->tree).begin();
  Iterator itr(this, it);
  return itr;
}

template <typename T>
typename Tree<T>::Iterator Tree<T>::end() {
 typename std::list<Node*>::iterator it = (this->tree).end();
  Iterator itr(this, it);
  return itr; 
}

// Assumed either parent is in the tree or the tree is empty
// so if parent is not found the tree is empty
template <typename T>
void Tree<T>::insert(const T& data, Tree<T>::Node* parent) {
  typename std::list<Tree<T>::Node*>::iterator it = std::find(tree.begin(), tree.end(), parent); /////////////////////
  if (it == tree.end()) {
    Node* root = new Node(data);
    tree.push_back(root);
    return;
  }
  Iterator itr(this, it);
  insert(data, itr);
  return;
}

template <typename T>
void Tree<T>::insert(const T& data, Iterator it) {
  // *(it.it) is a pointer to the parent for whom we will add a child to
  Node* p_child = new Node(data, *(it.it));
  // If the parent Node* is not null
  if (*(it.it) != nullptr) {
    // Make new node's parent point to Node corresponding to Iterator
    p_child->parent = *(it.it);
    // Look for the last child of the parent in the tree list given a pointer to the last child
    typename std::list<Node*>::iterator it_last_child = std::find(it.it, tree.end(), (*(it.it))->children.back());
    // Add new node to parent's children
    (*(it.it))->children.push_back(p_child);
    // If parent had no children
    if (it_last_child == tree.end()) {
      (tree.insert(++(it.it), p_child));
    }
    else {
      tree.insert(++it_last_child, p_child);
    }
  }
  // Node is root being inserted
  else {
    p_child->parent = p_child;
    tree.push_back(p_child);
  }
  return;
}

template <typename T>
bool Tree<T>::remove(const T& data) {
  for (typename std::list<Node*>::iterator it = tree.begin(); it != tree.end(); ++it) {
    if ((*it)->data == data) {
      Node* temp  = *it;
      // Not allowing removal of non leaf nodes (nodes with children)
      if (((*it)->children).empty() == false) {
	return false;
      }
      else {
	// Removing it from the list of Node* (the tree)
	tree.erase(it);
      }
      // Now remove it from its parent's children's list
      std::list<Node*>& children_list = temp->parent->children;
      typename std::list<Node*>::iterator it_children_beg = children_list.begin();
      typename std::list<Node*>::iterator it_children_end = children_list.end();
      typename std::list<Node*>::iterator it_child_match_data = std::find(it_children_beg, it_children_end, temp);
      tree.erase(it_child_match_data);
      return true;
    }
  }
  return false;
}

template <typename T>
bool Tree<T>::search(const T& data) {
  for (typename std::list<Node*>::iterator it = tree.begin(); it != tree.end(); ++it) {
    if ((*it)->data == data) {
      return true;
    }
  }
  return false;
}

template <typename T>
bool Tree<T>::empty() const {
  return tree.empty();
}

template <typename T>
int Tree<T>::size() const {
  return tree.size();
}

template <typename T>
int Tree<T>::leaves() const {
  int leaves = 0;
  for (typename std::list<Node*>::const_iterator it = tree.begin(); it != tree.end(); ++it) {
    if ((*it)->children.empty() == true) {
      ++leaves;
    }
  }
  return leaves;
}

template <typename T>
int Tree<T>::height() const {
  int height = -1;
  Node* root = tree.front();
  for (typename std::list<Node*>::const_iterator it = tree.begin(); it != tree.end(); ++it) {
    int i = 0;
    for (Node* temp = *it; temp != root; temp = temp->parent, ++i) {
      ;
    }
    if (i > height) {
      height = i;
    }
  }
  return height;
}

template <typename T>
int Tree<T>::level(Iterator it) const {
  // it is default value not pointing to anything
  if (it.it == typename std::list<Node*>::iterator()) {
    return -1;
  }
  // it not found in lits
  if (std::find(tree.begin(), tree.end(), *(it.it)) == tree.end()) {
    return -1;
  }
  int i = 0;
  Node* root = tree.front();
  for (Node* temp = *(it.it); temp != root; temp = temp->parent, ++i) {
    ;
  }
  return i;
}

template <typename T>
int Tree<T>::path_length() const {
  int path_length = 0;
  Node* root = tree.front();
  for (typename std::list<Node*>::const_iterator it = tree.begin(); it != tree.end(); ++it) {
    for (Node* temp = *it; temp != root; temp = temp->parent, ++path_length) {
      ;
    }
  }
  return path_length;
}

template <typename T>
bool Tree<T>::is_root(Iterator it) {
  // If it is its own parent, it is the rooto
  return ((*(it.it))->parent == *(it.it)) ? true : false;
}

template <typename T>
bool Tree<T>::is_leaf(Iterator it) {
  return (*(it.it))->children.empty() ? true : false;
}

template <typename T>
// How can this be constant
T& Tree<T>::root() const {
  return (tree.front())->data;
}
