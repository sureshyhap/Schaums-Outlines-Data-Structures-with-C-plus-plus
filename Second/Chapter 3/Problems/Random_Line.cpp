#include "Random_Line.h"

Random_Line::Random_Line() {
  _a = random.real();
  _b = random.real();
  _c = random.real();
}

Random Random_Line::random;
