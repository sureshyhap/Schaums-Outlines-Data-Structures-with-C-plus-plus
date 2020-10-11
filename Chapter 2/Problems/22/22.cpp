#include <iostream>

int** product(int a[3][4], int n1, int m1, int b[4][2], int n2, int m2);

int main(int argc, char* argv[]) {
  int a[3][4] = {{3, 6, 1, 7}, {2, 5, 4, 8}, {10, 5, 4, 2}};
  int b[4][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  int** matrix = product(a, 3, 4, b, 4, 2);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}

int** product(int a[3][4], int n1, int m1, int b[4][2], int n2, int m2) {
  if (m1 != n2){
    return NULL;
  }
  // Setting up the matrix
  int* (*result) = new int*[n1];
  for (int i = 0; i < n1; ++i) {
    result[i] = new int[m2];
  }
  for (int i = 0; i < n1; ++i) {
    for (int j = 0; j < m2; ++j) {
      result[i][j] = 0;
      for (int k = 0; k < m1; ++k) {
	result[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return result;
}
