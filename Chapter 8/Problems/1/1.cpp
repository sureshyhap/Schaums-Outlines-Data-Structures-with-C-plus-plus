#include <iostream>

typedef struct Min_Max {
  int min, max;
} Min_Max;

Min_Max findmm(int a[], int n);

int main(int argc, char* argv[]) {
  int a[] = {3, 8, 3, 1, 4, 3, 10, 5, 2, 6};
  Min_Max mm = findmm(a, sizeof(a) / sizeof(int));
  std::cout << "min = " << mm.min << "; max = " << mm.max;
  return 0;
}

// Assumes array has at least one element
Min_Max findmm(int a[], int n) {
  Min_Max mm;
  mm.min = a[0];
  mm.max = a[0];
  for (int i = 0; i < n; ++i) {
    if (a[i] < mm.min) {
      mm.min = a[i];
    }
    if (a[i] > mm.max) {
      mm.max = a[i];
    }
  }
  return mm;
}
