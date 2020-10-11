#include "Point.h"
#include <sstream>
#include <iostream>

Point::Point(double x, double y) : _x(x), _y(y) {
  std::cout << "DEFAULT CONSTRUCTOR INVOKED" << std::endl;
}

Point::Point(const Point& p) : _x(p._x), _y(p._y) {
  std::cout << "COPY CONSTRUCTOR INVOKED" << std::endl;
}

Point::~Point() {}

Point& Point::operator=(const Point& p) {
  std::cout << "ASSIGNMENT OPERATOR INVOKED" << std::endl;
  _x = p._x;
  _y = p._y;
  return *this;
}

double Point::x() const {
  return _x;
}

double Point::y() const {
  return _y;
}

std::string Point::toString() const {
  std::ostringstream os;
  os << '(' << _x << ',' << _y << ')';
  return os.str();
}
