#include <iostream>

int inner_product(int a[], int b[], int n);

int main(int argc, char* argv[]) {
  int a[3] = {4, 5, 6};
  int b[3] = {1, 2, 3};
  std::cout << inner_product(a, b, 3) << '\n';
  return 0;
}

int inner_product(int a[], int b[], int n) {
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += (a[i] * b[i]);
  }
  return sum;
}
