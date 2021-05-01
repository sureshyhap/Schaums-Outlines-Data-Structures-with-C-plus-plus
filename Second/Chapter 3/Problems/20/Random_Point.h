#ifndef RANDOM_POINT_H
#define RANDOM_POINT_H

#include <string>
#include "../Random.h"

class Line;
class Random_Point {
  friend class Line;  
  friend Random_Point operator-(const Random_Point& p);
  friend Random_Point operator+(const Random_Point& p1, const Random_Point& p2);
  friend Random_Point operator-(const Random_Point& p1, const Random_Point& p2);
  friend Random_Point operator*(const Random_Point& p1, const Random_Point& p2);
  friend Random_Point operator/(const Random_Point& p1, const Random_Point& p2);
  friend double distance(const Random_Point& p1, const Random_Point& p2);
 public:
  static const Random_Point ORIGIN;  
  Random_Point(double x = 0, double y = 0);
  Random_Point(double _x2, double _y2, double _x1, double _y1);
  Random_Point(const Random_Point& p);
  ~Random_Point();
  Random_Point& operator=(const Random_Point& p);
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
 private:
  double _x, _y, _r, _theta;
  double _x1, _x2, _y1, _y2;
  static Random random;
};

#endif // RANDOM_POINT_H
