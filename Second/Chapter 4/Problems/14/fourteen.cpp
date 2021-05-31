#include <iostream>

int a(int m, int n);

int a(int m, int n) {
  if (m == 0) {
    return 1;
  }
  if (m == 1 and n == 0) {
    return 2;
  }
  if (m > 1 and n == 0) {
    return m + 2;
  }
  if (m > 0 and n > 0) {
    return a(a(m - 1, n), n - 1);
  }
}

int main(int argc, char* argv[]) {
  std::cout << a(5, 2) << '\n';
  return 0;
}
