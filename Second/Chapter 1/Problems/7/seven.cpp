#include <iostream>
#include <iomanip>

int main(int argc, char* argv[]) {
  double amount = {}, monthly = {}, rate = {};
  std::cout << "Enter amount of loan (in $): ";
  std::cin >> amount;
  std::cout << "Enter monthly payment (in $): ";
  std::cin >> monthly;
  std::cout << "Enter interest rate (in %): ";
  std::cin >> rate;
  rate /= 100;
  rate /= 12;
  std::cout << "\nMonth   Interest     Amount";
  std::cout << "\n-----   --------    -------\n";
  std::cout << std::setw(5) << 0 << std::setw(22) << std::fixed << std::setprecision(2) << amount << '\n';
  int i = 1;
  while (amount > 0) {
    double interest = amount * rate;
    amount -= monthly;
    if (amount < 0){
      amount = 0;
      goto print;
    }
    amount += interest;
  print:
    std::cout << std::setw(5) << i++ << std::setw(11) << std::fixed << std::setprecision(2) << interest << std::setw(11) << std::fixed << std::setprecision(2) << amount << '\n';
  }
  
  std::cout << "-----   --------    -------\n";
  return 0;
}
