#include <iostream>

int euclidean(int m, int n);

int main(int argc, char* argv[]) {
  std::cout << euclidean(494, 130);
  return 0;
}

int euclidean(int m, int n) {
  if (n > m) {
    int temp = m;
    m = n;
    n = temp;
  }
  if (n == 0) {
    return m;
  }
  return euclidean(n, m % n);
}
