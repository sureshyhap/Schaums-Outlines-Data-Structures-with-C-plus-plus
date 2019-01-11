#ifndef POINT_H
#define POINT_H

#include <string>

class Point {
 public:
  Point(double = 0.0, double = 0.0);
  Point(const Point&);
  ~Point();
  Point& operator=(const Point&);
  double x() const;
  double y() const;
  std::string toString() const;
 protected:
  double _x, _y;
};

#endif // POINT_H
