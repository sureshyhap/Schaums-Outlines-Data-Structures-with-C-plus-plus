#include <iostream>

bool is_leap_year(int year);

int main(int argc, char* argv[]) {
  std::cout << std::boolalpha << is_leap_year(2000) << '\n';
  return 0;
}

bool is_leap_year(int year) {
  if (year % 400 == 0) {
    return true;
  }
  else if (year % 4 == 0) {
    if (year % 100 == 0) {
      return false;
    }
    else {
      return true;
    }
  }
  else {
    return false;
  }
}
