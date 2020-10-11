#include "Purse.h"
#include <iostream>
#include <cmath>

Purse::Purse() : pennies(0), nickels(0), dimes(0), quarters(0),
		 ideal_pennies(0), ideal_nickels(0), ideal_dimes(0), ideal_quarters(0) {}

Purse::Purse(double initial_money) {
  m = initial_money;
  calculate_ideal(m, ideal_pennies, ideal_nickels, ideal_dimes, ideal_quarters);
  pennies = ideal_pennies;
  nickels = ideal_nickels;
  dimes = ideal_dimes;
  quarters = ideal_quarters;
}

void Purse::insert(double money) {
  m += money;
  calculate_ideal(m, ideal_pennies, ideal_nickels, ideal_dimes, ideal_quarters);
  pennies = ideal_pennies;
  nickels = ideal_nickels;
  dimes = ideal_dimes;
  quarters = ideal_quarters;
}

void Purse::remove(double money) {
  m -= money;
  calculate_ideal(m, ideal_pennies, ideal_nickels, ideal_dimes, ideal_quarters);
  pennies = ideal_pennies;
  nickels = ideal_nickels;
  dimes = ideal_dimes;
  quarters = ideal_quarters;  
}

void Purse::print() const {
  std::cout << "Quarters: " << quarters << std::endl;
  std::cout << "Dimes: " << dimes << std::endl;
  std::cout << "Nickels: " << nickels << std::endl;
  std::cout << "Pennies: " << pennies << std::endl;
}

void Purse::calculate_ideal(double money, int& ip, int& in, int& id, int& iq) {
  iq =(round(money * 100)) / 25;
  money -= (iq * .25);
  id = (round(money * 100)) / 10;
  money -= (id * .10);
  in = (round(money * 100)) / 5;
  money -= (in * .05);
  ip = (round(money * 100)) / 1;
  money -= (ip * .01);
}
