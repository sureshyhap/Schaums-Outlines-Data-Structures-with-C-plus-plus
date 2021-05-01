#include "Random.h"

Random::Random(unsigned long seed) : r_num(seed) {
  if (not seed) {
    r_num = time(NULL);
  }
  randomize();
}

void Random::reset_r_num(unsigned long seed) {
  r_num = seed;
  if (not seed) {
    r_num = time(NULL);
  }
  randomize();
}

int Random::integer(unsigned long min, unsigned long max) {
  randomize();
  return min + (r_num / 10) % (max - min + 1);
}

double Random::real() {
  randomize();
  return static_cast<double>(r_num) / ULONG_MAX;
}

void Random::randomize() {
  r_num = (1103515245 * r_num + 123456789) % ULONG_MAX;
}
