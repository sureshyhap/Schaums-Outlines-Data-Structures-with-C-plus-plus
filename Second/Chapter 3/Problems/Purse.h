#ifndef PURSE_H
#define PURSE_H

#include <iostream>

class Purse {
  friend std::ostream& operator<<(std::ostream& os, const Purse& p);
 public:
  Purse(int p = 0, int n = 0, int d = 0, int q = 0);
  // Gets value in dollars
  double get_value() const;
  void insert(double dollars);
  // Will fail if can't remove the optimal amount of coins
  // even if it's possible to remove the amount
  bool remove(double dollars);
  void print() const;
 private:
  void set_value();
  int pennies, nickels, dimes, quarters;
  // Value in cents
  double value;
};

#endif // PURSE_H
