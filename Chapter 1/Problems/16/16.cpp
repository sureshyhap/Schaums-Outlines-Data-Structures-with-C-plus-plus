#include <iostream>

bool is_leap_year(int year);

int main(int argc, char* argv[]) {
  std::cout << "Enter a year: ";
  int year;
  std::cin >> year;
  std::cout << year << " is " << (is_leap_year(year) ? "a" : "not a") << " leap year.";
  return 0;
}

bool is_leap_year(int year) {
  if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) {
    return true;
  }
  else {
    return false;
  }
}
