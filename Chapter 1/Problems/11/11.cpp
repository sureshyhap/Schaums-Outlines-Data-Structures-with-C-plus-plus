#include <iostream>

double f_to_c(double farenheit);

int main(int argc, char* argv[]) {
  std::cout << "Enter a temperature in F: ";
  double f_temp;
  std::cin >> f_temp;
  std::cout << f_temp << " degrees F = " << f_to_c(f_temp) << " degrees C";
  
  return 0;
}

double f_to_c(double farenheit) {
  return (farenheit - 32) / 1.8;
}
