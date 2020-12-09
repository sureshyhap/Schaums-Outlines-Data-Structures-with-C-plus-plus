#include <iostream>

int min(int a[], int n);

int main(int argc, char* argv[]) {
  int a[] = {5, 1, 7, 3, 7, 3, 1, 7};
  std::cout << min(a, sizeof(a) / sizeof(int)) << '\n';
  return 0;
}

int min(int a[], int n) {
  if (n == 0) {
    return 0;
  }
  int minimum = a[0];
  for (int i = 1; i < n; ++i) {
    if (a[i] < minimum) {
      minimum = a[i];
    }
  }
  return minimum;
}
