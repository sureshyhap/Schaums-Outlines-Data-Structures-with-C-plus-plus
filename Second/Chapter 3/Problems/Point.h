#ifndef POINT_H
#define POINT_H

#include <string>

class Point {
 public:
  Point(double x = 0, double y = 0);
  Point(const Point& p);
  ~Point();
  Point& operator=(const Point& p);
  double x() const;
  double y() const;
  std::string to_string() const;
  double magnitude() const;
  double amplitude() const;
  double r() const;
  double theta() const;
  void rotate(double angle);
 private:
  double _x, _y, _r, _theta;
};

#endif // POINT_H
