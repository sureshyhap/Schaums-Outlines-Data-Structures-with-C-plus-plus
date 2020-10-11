#include "Hash_Table.h"

template <typename K, typename V>
Hash_Table<K, V>::Hash_Table(int cap, double load) {
  hash_table = std::vector<std::pair<K, V>>(cap);
  this->cap = cap;
  this->load = load;
}

template <typename K, typename V>
V& Hash_Table<K, V>::operator[](K index) {
  int ind = hash(index);
  // Linearly probe
  // This will never go on forever because we will rebuild
  // when the load gets too large
  while (hash_table[ind].first != index && hash_table[ind].first != K()) {
    ++ind;
    ind %= hash_table.size();
  }
  return hash_table[ind].second;
}

template <typename K, typename V>
int Hash_Table<K, V>::hash(K key) {
  // Only works for strings
  int sum = 0, len = key.length();
  for (int i = 0; i < len; ++i) {
    sum += (i + 1) * key[i];
  }
  return sum % cap;
}

template <typename K, typename V>
bool Hash_Table<K, V>::insert(K key, V value) {
  int ind = hash(key);
  while (hash_table[ind] != K()) {
    if (hash_table[ind] == key) {
      // Key already in table
      return false;
    }
  }
  if (size() + 1 < load * hash_table.size()) {
    hash_table[ind] = std::pair<K, V>(key, value);
  }
  else {
    rebuild();
    insert(key, value);
  }
  return true;
}

template <typename K, typename V>
bool Hash_Table<K, V>::remove(K key) {
  int ind = hash(key);
  while (hash_table[ind].first != key && hash_table[ind].first != K()) {
    ++ind;
    ind %= hash_table.size();
  }
  if (hash_table[ind].first == key) {
    hash_table[ind].first = std::pair<K, V>(K(), V());
    return true;
  }
  else {
    return false;
  }
}

template <typename K, typename V>
int Hash_Table<K, V>::size() const {
  int n = 0;
  int h_size = hash_table.size();
  for (int i = 0; i < h_size; ++i) {
    if (hash_table[i].first != K()) {
      ++n;
    }
  }
  return n;
}

template <typename K, typename V>
void Hash_Table<K, V>::print() const {
  for (int i = 0, len = hash_table.size(); i < len; ++i) {
    if (hash_table[i].first != K()) {
      std::cout << hash_table[i].first << ": " << hash_table[i].second << "\n";
    }
  }
}

template <typename K, typename V>
void Hash_Table<K, V>::rebuild() {
  std::vector<std::pair<K, V>> old(hash_table);
  hash_table.clear();
  hash_table = std::vector<std::pair<K, V>>(old.size() * 2);
  for (int i = 0, len = old.size(); i < len; ++i) {
    insert(old[i].first, old[i].second);
  }
  return;
}
