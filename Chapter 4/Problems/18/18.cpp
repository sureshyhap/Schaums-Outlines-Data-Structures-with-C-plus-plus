#include <iostream>

int euclidean(int m, int n);

int main(int argc, char* argv[]) {
  std::cout << euclidean(494, 130);
  return 0;
}

int euclidean(int m, int n) {
  while (m != n) {
    if (n > m) {
      int temp = m;
      m = n;
      n = temp;
    }
    while (m > n) {
      m = m - n;
    }
  }
  return m;
}
