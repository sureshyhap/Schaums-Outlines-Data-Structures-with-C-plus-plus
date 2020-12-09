#include <iostream>

int last_max_index(int a[], int n);

int main(int argc, char* argv[]) {
  int a[] = {3, 6, 1, 7, 4, 5, 7, 1};
  std::cout << last_max_index(a, sizeof(a) / sizeof(int)) << '\n';
  return 0;
}

int last_max_index(int a[], int n) {
  if (n == 0) {
    return -1;
  }
  int max = a[0];
  int max_index = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] >= max) {
      max = a[i];
      max_index = i;
    }
  }
  return max_index;
}
