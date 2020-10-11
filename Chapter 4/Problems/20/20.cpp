#include <iostream>

int euclidean(int m, int n);

int main(int argc, char* argv[]) {
  std::cout << euclidean(494, 130);
  return 0;
}

int euclidean(int m, int n) {
  while (n != 0) {
    int temp = n;
    n = m % n;
    m = temp;
  }
  return m;
}
