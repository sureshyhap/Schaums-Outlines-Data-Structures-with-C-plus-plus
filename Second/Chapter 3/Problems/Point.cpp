#include "Point.h"
#include <sstream>
#include <iostream>
#include <cmath>

Point::Point(double x, double y) : _x(x), _y(y), _r(magnitude()), _theta(amplitude()) {
  std::cout << "DEFAULT CONSTRUCTOR INVOKED\n";
}

Point::Point(const Point& p) : _x(p._x), _y(p._y), _r(p._r), _theta(p._theta) {
  std::cout << "COPY CONSTRUCTOR INVOKED\n";
}

Point::~Point() {

}

Point& Point::operator=(const Point& p) {
  _x = p._x;
  _y = p._y;
  _r = p._r;
  _theta = p._theta;
  std::cout << "ASSIGNMENT OPERATOR INVOKED\n";  
  return *this;
}

double Point::x() const {
  return _x;
}

double Point::y() const {
  return _y;
}

std::string Point::to_string() const {
  std::ostringstream oss;
  oss << "(" << _x << ", " << _y << ")";
  return oss.str();
}

double Point::magnitude() const {
  return sqrt(pow(_x, 2) + pow(_y, 2));
}

double Point::amplitude() const {
  return atan(_y / _x);
}

double Point::r() const {
  return _r;
}

double Point::theta() const {
  return _theta;
}

void Point::rotate(double angle) {
  _theta += angle;
  _x = _r * cos(_theta);
  _y = _r * sin(_theta);
}
