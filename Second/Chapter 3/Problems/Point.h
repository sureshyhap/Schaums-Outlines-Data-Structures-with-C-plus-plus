#ifndef POINT_H
#define POINT_H

#include <string>

class Line;
class Point {
  friend class Line;  
  friend Point operator-(const Point& p);
  friend Point operator+(const Point& p1, const Point& p2);
  friend Point operator-(const Point& p1, const Point& p2);
  friend Point operator*(const Point& p1, const Point& p2);
  friend Point operator/(const Point& p1, const Point& p2);
  friend double distance(const Point& p1, const Point& p2);
 public:
  static const Point ORIGIN;  
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
  double distance_to(const Line& l) const;
  bool is_on(const Line& l) const;
 protected:
  double _x, _y, _r, _theta;
};

#endif // POINT_H
