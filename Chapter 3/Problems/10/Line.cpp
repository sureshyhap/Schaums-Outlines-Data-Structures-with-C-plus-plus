#include "Line.h"
#include <sstream>

std::ostream& operator<<(std::ostream& os, const Line& l) {
  os << l.to_string();
}

Line::Line(double x0, double y0) : _a(y0), _b(x0), _c(-x0 * y0) {}

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
