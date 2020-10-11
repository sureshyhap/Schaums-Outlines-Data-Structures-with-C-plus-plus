#ifndef RANDOM_H
#define RANDOM_H

#include <climits>
#include <ctime>
#include <cstdlib>

class Random {
 public:
  Random(unsigned long = 0);
  void reset_seed(unsigned long = 0);
  int integer(unsigned long = ULONG_MAX, unsigned long = 1);
  double real();
 protected:
  unsigned long _seed;
  void randomize();
};

#endif // RANDOM_H
