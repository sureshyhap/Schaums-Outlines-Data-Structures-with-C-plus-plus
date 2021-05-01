#include "Point.h"
#include <sstream>
#include <iostream>
#include <cmath>

Point operator-(const Point& p) {
  return Point(-p._x, -p._y);
}

Point operator+(const Point& p1, const Point& p2) {
  return Point(p1._x + p2._x, p1._y + p2._y);
}

Point operator-(const Point& p1, const Point& p2) {
  return Point(p1._x - p2._x, p1._y - p2._y);
}

Point operator*(const Point& p1, const Point& p2) {
  return Point(p1._x * p2._x, p1._y * p2._y);
}

Point operator/(const Point& p1, const Point& p2) {
  return Point(p1._x / p2._x, p1._y / p2._y);
}

double distance(const Point& p1, const Point& p2) {
  return sqrt(pow(p2._x - p1._x, 2) + pow(p2._y - p1._y, 2));
}

const Point Point::ORIGIN;

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

// Including this because the following Point member functions
// work with Line objects
class Line {
  friend class Point;
  // ax + by + c = 0
  double _a, _b, _c;
};

double Point::distance_to(const Line& l) const {
  double num = abs(l._a * _x + l._b * _y + l._c);
  // If den == 0, will return inf
 double den = sqrt(pow(l._a, 2) + pow(l._b, 2));
 return num / den;
}

bool Point::is_on(const Line& l) const {
  // Beware checking for equality for a double
  if (distance_to(l) == 0) {
    return true;
  }
  else {
    return false;
  }
}
