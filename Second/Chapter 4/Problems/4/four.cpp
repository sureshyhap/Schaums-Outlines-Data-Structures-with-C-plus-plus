#include <iostream>

int max(const int* const arr, int n);

int max(const int* const arr, int n) {
  if (n == 1) {
    return arr[0];
  }
  int m = max(arr, n - 1);
  return arr[n - 1] > m ? arr[n - 1] : m;
}

int main(int argc, char* argv[]) {
  int a[] = {3, 6, 7, 3, 1, 7, 9, 4, 5, 2};
  int n = sizeof(a) / sizeof(int);
  std::cout << max(a, n) << '\n';
}
