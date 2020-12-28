#include <iostream>

int** outer_product(int a[], int b[], int n);

int main(int argc, char* argv[]) {
  int a[] = {1, 2, 3, 4};
  int b[] = {5, 6, 7, 8};
  int n = sizeof(a) / sizeof(int);
  int** op = outer_product(a, b, n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << op[i][j] << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}

int** outer_product(int a[], int b[], int n) {
  int* (*result) = new int*[n];
  for (int i = 0; i < n; ++i) {
    result[i] = new int[n];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0 ; j < n; ++j
	 ) {
      result[i][j] = a[i] * b[j];
    }
  }
  return result;
}
