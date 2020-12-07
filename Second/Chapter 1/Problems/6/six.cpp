#include <iostream>
#include <iomanip>

double calculate_tax(double income);

int main(int argc, char* argv[]) {
  double income = {};
  std::cout << "Enter your income: ";
  std::cin >> income;
  double tax = calculate_tax(income);
  std::cout << "You owe $" << std::fixed << std::setprecision(2) << tax << "\n";
  return 0;
}

double calculate_tax(double income) {
  double tax = {};
  if (income > 0 and income <= 22'100) {
    tax = income * .15;
  }
  else if (income > 22'100 and income <= 53'500) {
    double amount_over = income - 22'100;
    tax = 3'315 + .28 * amount_over;
  }
  else if (income > 53'500 and income <= 115'000) {
    double amount_over = income - 53'500;
    tax = 12'107 + .31 * amount_over;
  }
  else if (income > 115'000 and income <= 250'000) {
    double amount_over = income - 115'000;
    tax = 31'172 + .36 * amount_over;
  }
  else if (income > 250'000) {
    double amount_over = income - 250'000;
    tax = 79'772 + .396 * amount_over;
  }
  return tax;
}
