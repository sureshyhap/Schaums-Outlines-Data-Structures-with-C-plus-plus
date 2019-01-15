#include <iostream>

int sum_elements(int a[], int n);

int main(int argc, char* argv[]) {
  int a[] = {3, 5, 3, 6, 8, 2, 5, 4, 3};
  std::cout << sum_elements(a, 5);
  return 0;
}

int sum_elements(int a[], int n) {
  if (n == 0) {
    return 0;
  }
  return a[n - 1] + sum_elements(a, n - 1);
}
