#include <iostream>

int factorial(int num);
double power(double x, int n);

int main(int argc, char* argv[]) {
  std::cout << "Enter x (power of e^x): ";
  double x = 0;
  std::cin >> x;
  std::cout << "How many terms of the power series expansion would you like?: ";
  int terms = 0;
  std::cin >> terms;

  double sum = 0; 
  for (int i = 0; i < terms; ++i) {
    sum += (power(x, i)  / factorial(i));
  }

  std::cout << "e^" << x << "is approximately: " << sum << std::endl;
}

int factorial(int num) {
  int fact = 1;
  for (int i = num; i > 0; --i) {
    fact *= i;
  }
  return fact;
}

double power(double x, int n) {
  double product = 1;
  for (int i = 0; i < n; ++i) {
    product *= x;
  }
  return product;
}
