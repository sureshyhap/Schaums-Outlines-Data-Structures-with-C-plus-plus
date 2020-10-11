#include <iostream>

int max_index(int a[], int n);

int main(int argc, char* argv[]) {
  int a[] = {3, 6, 4, 7, 3, 4, 5, 3, 7, 5};
  std::cout << max_index(a, sizeof(a) / sizeof(int));
  return 0;
}

int max_index(int a[], int n) {
  int max = a[0];
  int max_index = 0;
  int i = 1;
  for (; i < n; ++i) {
    if (a[i] >= max) {
      max = a[i];
      max_index = i;
    }
  }
  return max_index;
}
