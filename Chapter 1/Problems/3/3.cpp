#include <cmath>
#include <iostream>

int main(int argc, char* argv[]) {
  // implements the quadratic formula
  double a, b, c;
  std::cout << "Enter the coefficients of a quadratic equation:" << std::endl;
  std::cout << "\ta: ";
  std::cin >> a;
  std::cout << "\tb: ";
  std::cin >> b;
  std::cout << "\tc: ";
  std::cin >> c;
  std::cout << "The equation is: " << a << "*x*x + " << b
	    << "*x + " << c << " = 0\n";
  if (a == 0) {
    std::cout << "The solution is: \n";
    std::cout << -c / b;
    return 0;
  }
  double d = b*b - 4*a*c; // discriminant
  if (d < 0) {
    std::cout << "The discriminant, d = " << d
	      << " < 0, so there are no real solutions.\n";
    return 0;
  }
  double sqrtd = sqrt(d);
  double x1 = (-b + sqrtd) / (2 * a);
  double x2 = (-b - sqrtd) / (2 * a);
  std::cout << "The solutions are:\n";
  std::cout << "\tx1 = " << x1 << std::endl;
  std::cout << "\tx2 = " << x2 << std::endl;
  std::cout << "Check:";
  std::cout << "\ta*x1*x1 + b*x1 + c = " << a*x1*x1 + b*x1 + c;
  std::cout << "\n\ta*x2*x2 + b8 x2 + c = " << a*x2*x2 + b*x2 + c;
}

