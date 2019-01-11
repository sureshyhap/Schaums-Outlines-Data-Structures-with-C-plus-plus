#ifndef LINE_H
#define LINE_H

#include <string>
#include <iostream>
#include "Point.h"

class Line {
  friend std::ostream& operator<<(std::ostream&, const Line&);
  friend bool are_parallel(const Line&, const Line&);
  friend bool are_perpendicular(const Line&, const Line&);
  friend double angle(const Line&, const Line&);
 public:
  Line(double = 1.0, double = 1.0); // two-intercept form
  Line(const Point&, double = 0.0); // point-slope form
  Line(const Point&, const Point&); // two-point form
  Line(double, double, double); // general form
  Line(const Line&); // copy constructor
  ~Line(); // destructor
  Line& operator=(const Line&); // assignment operator
  double x_coeff() const;
  double y_coeff() const;
  double c_term() const;
  double slope() const;
  std::string to_string() const;
  double x_intercept() const;
  double y_intercept() const;
  bool is_horizontal() const;
  bool is_vertical() const;
  double distance(const Point&) const;
  bool contains(const Point&) const;
 protected:
  double _a, _b, _c;
};

#endif // LINE_H
