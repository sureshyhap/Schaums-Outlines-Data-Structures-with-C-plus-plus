#ifndef RANDOM_H
#define RANDOM_H

#include <cstdlib>
#include <ctime>
#include <climits>

class Random {
public:
  Random(unsigned long seed = 0);
  void reset_r_num(unsigned long seed = 0);
  int integer(unsigned long min = 1, unsigned long max = ULONG_MAX);
  double real();
private:
  unsigned long r_num;
  void randomize();
};

#endif // RANDOM_H
