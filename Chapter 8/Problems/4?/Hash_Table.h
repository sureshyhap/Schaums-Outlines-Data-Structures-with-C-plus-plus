#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <vector>
#include <iostream>

template <typename K, typename V>
class Hash_Table {
 public:
  Hash_Table(int cap = 100, double load = .75);
  V& operator[](K index);
  bool insert(K key, V value);
  bool remove(K key);
  int size() const;
  void print() const;
 protected:
  int hash(K key);
  void rebuild();
  int cap;
  double load;
  std::vector<std::pair<K, V>> hash_table;
};

#endif // HASH_TABLE_H
