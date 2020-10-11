#include <iostream>

int inner_product(int a[], int b[], int n);

int main(int argc, char* argv[]) {
  int a[4] = {3, 5, 1, 1};
  int b[4] = {6, 1, 7, 3};
  std::cout << inner_product(a, b, 4);
  return 0;
}

int inner_product(int a[], int b[], int n) {
  int total = 0;
  for (int i = 0; i < n; ++i) {
    total += (a[i] * b[i]);
  }
  return total;
}
