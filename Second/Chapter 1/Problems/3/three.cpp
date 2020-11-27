#include <iostream>
#include <cmath>

// Implements the quadratic formula
int main(int argc, char* argv[]) {
  double a = {}, b = {}, c = {};
  std::cout << "Enter the coefficients of a quadratic equation:\n" ;
  std::cout << "\ta: ";
  std::cin >> a;
  std::cout << "\tb: ";
  std::cin >> b;
  std::cout << "\tc: ";
  std::cin >> c;
  std::cout << "The equation is " << a << "*x^2 + " << b << "*x + " << c << " = 0\n";
  if (!a) {
    std::cout << "The single solution is x = " << -c / b << '\n';
    return 0;
  }
  // Discriminant
  double d = {b*b - 4*a*c};
  if (d < 0) {
    std::cout << "The discriminant, d = " << d << " < 0, so there are no real solutions.\n";
    return 0;
  }
  double sqrtd = {sqrt(d)};
  double x1 = {(-b + sqrtd) / (2 * a)};
  double x2 = {(-b - sqrtd) / (2 * a)};
  std::cout << "The solutions are:\n";
  std::cout << "\tx1 = " << x1 << '\n';
  std::cout << "\tx2 = " << x2 << '\n';
  std::cout << "Check:";
  std::cout << "\ta*x1^2 + b*x1 + c = " << a * x1 * x1 + b * x1 + c;
  std::cout << "\n\ta*x2^2 + b*x2 + c = " << a * x2 * x2 + b * x2 + c;
  return 0;
}
