#ifndef RANDOMPOINT_H
#define RANDOMPOINT_H

#include <string>

class RandomPoint {
  friend RandomPoint operator-(const RandomPoint&);
  friend RandomPoint operator+(const RandomPoint&, const RandomPoint&);
  friend RandomPoint operator-(const RandomPoint&, const RandomPoint&);
  friend RandomPoint operator*(const double, const RandomPoint&);
  friend RandomPoint operator/(const RandomPoint&, const double);
  friend double distance(const RandomPoint&, const RandomPoint&);
 public:
  RandomPoint(double = 1.0, double = 1.0, double = 0.0, double = 0.0);
  RandomPoint(const RandomPoint&);
  ~RandomPoint();
  RandomPoint& operator=(const RandomPoint&);
  double x() const;
  double y() const;
  std::string toString() const;
  double magnitude() const;
  double amplitude() const;
  void rotate(double);
  static const RandomPoint ORIGIN;
 protected:
  double _x, _y;
  double _x1, _x2, _y1, _y2;
  static Random _random;
};

#endif // RANDOMPOINT_H
