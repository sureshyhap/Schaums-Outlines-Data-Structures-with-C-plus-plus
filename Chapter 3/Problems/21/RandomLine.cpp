#include "RandomLine.h"

Random RandomLine::_random;

RandomLine::RandomLine(double a2, double b2, double c2,
		       double a1, double b1, double c1) :
  _a1(a1), _a2(a2), _b1(b1), _b2(b2), _c1(c1), _c2(c2) {
  double a = _random.real();
  _a = (_a2 - _a1) * a + _a1;
  double b = _random.real();
  _b = (_b2 - _b1) * b + _b1;
  double c = _random.real();
  _c = (_c2 - _c1) * c + _c1;  
}
