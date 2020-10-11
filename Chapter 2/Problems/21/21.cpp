#include <iostream>

int** outer_product(int a[], int b[], int n);

int main(int argc, char* argv[]) {
  int a[] = {1, 3, 2, 5};
  int b[] = {6, 4, 2, 1};
  int** matrix = outer_product(a, b, 4);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    delete matrix[i];
    std::cout << std::endl;
  }
  delete matrix;
  return 0;
}

int** outer_product(int a[], int b[], int n) {
  int* (*matrix) = new int*[n];
  for (int i = 0; i < n; ++i) {
    matrix[i] = new int[n];
    for (int j = 0; j < n; ++j) {
      matrix[i][j] = a[i] * b[j];
    }
  }
  return matrix;
}
