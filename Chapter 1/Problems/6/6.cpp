#include <iostream>

int main(int argc, char* argv[]) {
  double salary;
  std::cout << "Enter salary: ";
  std::cin >> salary;
  double tax;

  if (salary > 0 && salary <= 22100) {
    tax = .15 * salary;
  }
  else if (salary > 22100 && salary <= 53500) {
    tax = 3315 + (.28 * (salary - 22100));
  }
  else if (salary > 53500 && salary <= 115000) {
    tax = 12107 + (.31 * (salary - 53500));
  }
  else if (salary > 115000 && salary <= 250000) {
    tax = 31172 + (.36 * (salary - 115000));
  }
  else if (salary > 250000) {
    tax = 79772+ .396 * (salary - 250000);
  }

  std::cout << "\nYour tax is: " << tax;
  
  return 0;
}
