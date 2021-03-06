#include "Line.h"
#include <sstream>
#include <cmath>
#define PI 3.14159265359

const Line Line::X_AXIS(0, 1, 0);
const Line Line::Y_AXIS(1, 0, 0);
const Line Line::DIAGONAL(1, -1, 0);

std::ostream& operator<<(std::ostream& os, const Line& l) {
  os << l.to_string();
}

bool are_parallel(const Line& line1, const Line& line2) {
  if (line1._b == 0) {
    if (line2._b == 0) {
      return true;
    }
    else {
      return false;
    }
  }
  else if (line2._b == 0) {
    return false;
  }
  return line1.slope() == line2.slope();
}

bool are_perpendicular(const Line& line1, const Line& line2) {
  if (line1._b == 0) {
    if (line2._a == 0) {
      return true;
    }
    else {
      return false;
    }
  }
  else if (line2._b == 0) {
    if (line1._a == 0) {
      return true;
    }
    else {
      return false;
    }
  }
  return (line1.slope() * line2.slope() == -1);
}

double angle(const Line& line1, const Line& line2) {
  if (are_parallel(line1, line2) == true) {
    return 0;
  }
  else if (are_perpendicular(line1, line2) == true) {
    return PI / 2;
  }

  double numerator = line2.slope() - line1.slope();
  double denominator = 1 + line2.slope() * line1.slope();
  return atan(numerator / denominator);
}

Line::Line(double m, double b) : _a(m), _b(-1), _c(b) {}

Line::Line(const Point& p, double m) : _a(m), _b(-1), _c(p._y - m * p._x) {}

Line::Line(double a, double b, double c) : _a(a), _b(b), _c(c) {}

Line::Line(const Line& l) : _a(l._a), _b(l._b), _c(l._c) {}

Line::~Line() {}

Line& Line::operator=(const Line& l) {
  _a = l._a;
  _b = l._b;
  _c = l._c;
  return *this;
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
  std::ostringstream os;
  os << _a << "x + " << _b << "y + " << _c << " = 0";
  return os.str();
}

double Line::slope() const {
  return -_a / _b;
}

double Line::x_intercept() const {
  return -_c / _a;
}

double Line::y_intercept() const {
  return -_c / _b;
}

bool Line::is_horizontal() const {
  return _a == 0 ? true : false;
}

bool Line::is_vertical() const {
  return _b == 0 ? true : false;
}

double Line::distance(const Point& p) const {
  double numerator = fabs(_a * p._x + _b * p._y + _c);
  double denominator = p.magnitude();
  return numerator / denominator;
}

bool Line::contains(const Point& p) const {
  return (_a * p._x + _b * p._y + _c == 0 ? true : false);
}
