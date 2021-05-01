#ifndef LINE_H
#define LINE_H

#include "Point.h"
#include <string>
#include <sstream>

class Line {
  friend class Point;
  friend bool are_parallel(const Line& line, const Line& line2);
  friend bool are_perpendicular(const Line& line, const Line& line2);
  friend double angle(const Line& line, const Line& line2);
 public:
  static const Line X_AXIS;
  static const Line Y_AXIS;
  static const Line DIAGONAL;
  // Slope-intercept form of a line
  // y = slope * x + y_int
  Line(double slope = 0.0, double y_int = 0.0);
  //////////// Two-intercept form of a line
  //////////// (y_int * x) + (x_int * y) = x_int * y_int
  ////////////  Line(double x_int = 1.0, double y_int = 1.0);
  // Point-slope form of a line
  // y - p._y = slope * (x - p._x)
  Line(const Point& p, double slope = 0.0);
  // Two-point form of a line
  // y - p1._y = ((p2._y - p1._y) / (p2._x - p1._x)) * (x - p1._x))
  Line(const Point& p1, const Point& p2);
  // General form of a line
  // a * x + b * y + c = 0
  Line(double a, double b, double c);
  Line(const Line& l);
  ~Line();
  Line& operator=(const Line& l);
  inline double x_coeff() const;
  inline double y_coeff() const;
  inline double c_term() const;
  std::string to_string() const;
  double slope() const;
  double x_intercept() const;
  double y_intercept() const;
  bool is_horizontal() const;
  bool is_vertical() const;
  double distance_to(const Point& p) const;
  bool contains(const Point& p) const;
 protected:
  // ax + by + c = 0
  double _a, _b, _c;
};

#endif //LINE_H
