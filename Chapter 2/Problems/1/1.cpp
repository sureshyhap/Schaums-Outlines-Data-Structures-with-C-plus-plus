#include <iostream>

int min(int a[], int n);

int main(int argc, char* argv[]) {
  int a[] = {4, 7, 5, 2, 5, 4};
  std::cout << min(a, sizeof(a) / sizeof(int));
  return 0;
}

int min(int a[], int n) {
  int min = a[0];
  for (int i = 1; i < n; ++i) {
    if (a[i] < min) {
      min = a[i];
    }
  }
  return min;
}
