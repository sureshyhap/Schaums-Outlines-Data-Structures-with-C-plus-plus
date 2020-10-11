#include <iostream>

int max(int a[], int n);

int main(int argc, char* argv[]) {
  int a[] = {4, 7, 2, 7, 5, 67, 5, 7};
  std::cout << max(a, 8);
  return 0;
}

int max(int a[], int n) {
  if (n == 0) {
    return a[0];
  }
  int max_first_set = max(a, n - 1);
  return max_first_set > a[n - 1] ? max_first_set : a[n - 1];
}
