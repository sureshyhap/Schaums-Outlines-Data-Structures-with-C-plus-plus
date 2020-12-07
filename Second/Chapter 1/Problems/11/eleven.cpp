#include <iostream>

double fahr_to_cel(double cel_temp);

int main(int argc, char* argv[]) {
  std::cout << fahr_to_cel(212) << '\n';
  return 0;
}

double fahr_to_cel(double cel_temp) {
  return (cel_temp - 32) / 1.8;
}
