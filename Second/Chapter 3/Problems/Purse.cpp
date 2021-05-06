#include "Purse.h"

std::ostream& operator<<(std::ostream& os, const Purse& p) {
  os << "Value: $" << (p.value < 100 ? "0." : "") << p.get_value() << '\n';
  os << "Pennies: " << p.pennies << '\n';
  os << "Nickels: " << p.nickels << '\n';
  os << "Dimes: " << p.dimes << '\n';
  os << "Quarters: " << p.quarters << "\n\n";
  return os;
}

Purse::Purse(int p, int n, int d, int q) : pennies(p), nickels(n), dimes(d), quarters(q) {
  set_value();
}

double Purse::get_value() const {
  return value / 100;
}

void Purse::insert(double dollars) {
  int cents = dollars * 100;
  quarters += (cents / 25);
  cents %= 25;
  dimes += (cents / 10);
  cents %= 10;
  nickels += (cents / 5);
  cents %= 5;
  pennies += (cents);
  set_value();
}

bool Purse::remove(double dollars) {
  int cents = dollars * 100;
  int q = cents / 25;
  if (q > quarters) {
    return false;
  }
  cents %= 25;
  int d = cents / 10;
  if (d > dimes) {
    return false;
  }
  cents %= 10;
  int n = cents / 5;
  if (n > nickels) {
    return false;
  }
  cents %= 5;
  int p = cents;
  if (p > pennies) {
    return false;
  }
  quarters -= q;
  dimes -= d;
  nickels -= n;
  pennies -= p;
  set_value();
  return true;
}

void Purse::print() const {
  std::cout << *this;
}

void Purse::set_value() {
  value = 1 * pennies + 5 * nickels + 10 * dimes + 25 * quarters;
}
