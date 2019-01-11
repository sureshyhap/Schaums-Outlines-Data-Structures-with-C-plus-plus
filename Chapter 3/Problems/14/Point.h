#ifndef POINT_H
#define POINT_H

#include <string>

class Point {
  friend class Line;
  friend Point operator-(const Point&);
  friend Point operator+(const Point&, const Point&);
  friend Point operator-(const Point&, const Point&);
  friend Point operator*(const double, const Point&);
  friend Point operator/(const Point&, const double);
  friend double distance(const Point&, const Point&);
 public:
  Point(double = 0.0, double = 0.0);
  Point(const Point&);
  ~Point();
  Point& operator=(const Point&);
  double x() const;
  double y() const;
  std::string toString() const;
  double magnitude() const;
  double amplitude() const;
  void rotate(double);
  static const Point ORIGIN;
 protected:
  double _x, _y;
};

#endif // POINT_H
