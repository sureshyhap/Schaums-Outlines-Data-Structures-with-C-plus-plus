#include "Line.h"
#include <iostream>
#include <cmath>
#include <cfloat>

bool are_parallel(const Line& line, const Line& line2) {
  // Beware testing for equality of doubles
  if (line.slope() == line2.slope()) {
    return true;
  }
  else {
    return false;
  }
}

bool are_perpendicular(const Line& line, const Line& line2) {
  // Beware checking for exact value equality of a double
  if (line.slope() * line2.slope() == -1) {
    return true;
  }
  else {
    return false;
  }
}

double angle(const Line& line, const Line& line2) {
  double slope1 = line.slope();
  double slope2 = line2.slope();
  double expression = (slope2 - slope1) / (1 + slope1 * slope2);
  return atan(expression);
}

Line::Line(double x_int, double y_int) : _a(y_int), _b(x_int), _c(-x_int * y_int) {
  
}

Line::Line(const Point& p, double slope) : _a(slope), _b(-1), _c(p._y - slope * p._x) {
  
}

Line::Line(const Point& p1, const Point& p2) : _a(p2._y - p1._y), _b(p1._x - p2._x), _c(p2._x * p1._y - p1._x * p2._y){
  
}

Line::Line(double a, double b, double c) : _a(a), _b(b), _c(c) {
  
}

Line::Line(const Line& l) : _a(l._a), _b(l._b), _c(l._c) {
  
}

Line::~Line() {
  
}

Line& Line::operator=(const Line& l) {
  _a = l._a;
  _b = l._b;
  _c = l._c;
  return * this;
}

double Line::x_coeff() const {
  return _a;
}

double Line::y_coeff() const {
  return _b;
}

double Line::c_term() const {
  return _c;
}

std::string Line::to_string() const {
  std::ostringstream oss;
  oss << _a << "x + " << _b << "y + " << _c << " = 0";
  return oss.str();
}

double Line::slope() const {
  try {
    if (_b == 0) {
      throw std::runtime_error("Division by zero");
    }
    else {
      return -_a / _b;
    }
  }
  catch (const std::runtime_error& re) {
    std::cerr << re.what() << '\n';
    return DBL_MAX;
  }
}

double Line::x_intercept() const {
  // If _a == 0, will return -inf
  return -_c / _a;
}

double Line::y_intercept() const {
  // If _b == 0, will return -inf  
  return -_c / _b;
}

bool Line::is_horizontal() const {
  return _a == 0;
}

bool Line::is_vertical() const {
  return _b == 0;
}

double Line::distance_to(const Point& p) const {
  double num = abs(_a * p._x + _b * p._y + _c);
  // If den == 0, will return inf
  double den = sqrt(pow(_a, 2) + pow(_b, 2));
  return num / den;
}

bool Line::contains(const Point& p) const {
  // Beware checking if a double is exactly 0
  if (distance_to(p) == 0) {
    return true;
  }
  else {
    return false;
  }
}

const Line Line::X_AXIS(0, 1, 0);

const Line Line::Y_AXIS(1, 0, 0);

const Line Line::DIAGONAL(1, -1, 0);
