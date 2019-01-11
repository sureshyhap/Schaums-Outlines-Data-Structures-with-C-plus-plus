#include "Point.h"
#include <sstream>
#include <iostream>
#include <cmath>
#define PI 3.14159265359

Point operator-(const Point& p) {
  return Point(-1 * p._x, -1 *p._y);
}

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

double Point::magnitude() const {
  return sqrt(_x * _x + _y * _y);
}

double Point::amplitude() const {
  double rads = atan(_y / _x);
}
  
void Point::rotate(double angle) {
  double new_angle = angle + amplitude();
  double radius = magnitude();
  _x = radius * cos(new_angle);
  _y = radius * sin(new_angle);
}
