#include <iostream>

int ackermann(int m, int n);

int main(int argc, char* argv[]) {
  std::cout << ackermann(5, 4);
  return 0;
}

int ackermann(int m, int n) {
  if (m == 0) {
    return 1;
  }
  if (m == 1 && n == 0) {
    return 2;
  }
  if (m > 1 && n == 0) {
    return m + 2;
  }
  return ackermann(ackermann(m - 1, n), n - 1);
}
