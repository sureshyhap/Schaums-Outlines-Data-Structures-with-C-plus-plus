#ifndef PURSE_H
#define PURSE_H

class Purse {
 public:
  Purse();
  Purse(double initial_money);
  void insert(double money);
  void remove(double money);
  void print() const;
 protected:
  int pennies, nickels, dimes, quarters;
  int ideal_pennies, ideal_nickels, ideal_dimes, ideal_quarters;
  double m;
  void calculate_ideal(double money, int& ip, int& in, int& id, int& iq);
};

#endif //PURSE_H
