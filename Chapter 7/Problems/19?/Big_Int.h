#ifndef BIG_INT_H
#define BIG_INT_H

#include <list>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>

class Big_Int {
  friend Big_Int operator-(const Big_Int& bi);
  friend Big_Int operator+(const Big_Int& bi1, const Big_Int& bi2);
  friend Big_Int operator-(const Big_Int& bi1, const Big_Int& bi2);
  friend Big_Int operator*(const Big_Int& bi1, const Big_Int& bi2);
  friend Big_Int operator*(int n, const Big_Int& b);
  friend Big_Int operator*(const Big_Int& b, int n);
  friend std::istream& operator>>(std::istream& is, Big_Int& b);
  friend bool find_bigger(const Big_Int& bi1, const Big_Int& bi2, Big_Int& bigger, Big_Int& smaller);
 public:
  Big_Int();
  Big_Int(std::string num);
  Big_Int(const Big_Int& bi);
  void print() const;
  Big_Int& operator=(const Big_Int& bi);
  bool operator==(const Big_Int& bi);
  bool operator<(const Big_Int& bi);
  bool operator<=(const Big_Int& bi);
  bool operator>(const Big_Int& bi);
  bool operator>=(const Big_Int& bi);
  bool operator!=(const Big_Int& b);
  Big_Int& operator+=(const Big_Int& b);
  Big_Int& operator-=(const Big_Int& b);
  Big_Int& operator*=(int n);
  Big_Int& operator*=(const Big_Int& b);
  static const int DIGITS_PER_NODE;
  static const int VALUES_PER_NODE;
 protected:

  std::list<int> number;
  bool is_neg;
};

#endif // BIG_INT_H
