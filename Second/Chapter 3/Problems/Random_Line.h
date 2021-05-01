#ifndef RANDOM_LINE_H
#define RANDOM_LINE_H

#include "Line.h"
#include "Random.h"
#include "Point.h"

class Random_Line : public Line {
 public:
  Random_Line();
 protected:
  static Random random;
};

#endif // RANDOM_LINE_H
