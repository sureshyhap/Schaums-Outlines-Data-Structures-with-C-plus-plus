#ifndef RANDOMLINE_H
#define RANDOMLINE_H

#include "Line.h"
#include "Random.h"

class RandomLine : public Line {
 public:
  RandomLine(double = 1.0, double = 1.0, double = 1.0,
	     double = 0.0, double = 0.0, double = 0.0);
 protected:
  double _a1, _a2, _b1, _b2, _c1, _c2;
  static Random _random;
};

#endif // RANDOMLINE_H
