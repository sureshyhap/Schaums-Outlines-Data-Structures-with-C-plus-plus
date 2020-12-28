#include <iostream>

constexpr int N1 = 2, N2 = 3, N3 = 3;

int** matrix_product(int a[N1][N2], int b[N2][N3]);

int main(int argc, char* argv[]) {
  int a[N1][N2] = {
    {1, 2, 3}, {4, 5, 6}
  };
  int b[N2][N3] = {
    {6, 5, 7}, {4, 3, 8}, {2, 1, 9}
  };
  int** result = matrix_product(a, b);
  for (int i = 0; i < N1; ++i) {
    for (int j = 0; j < N3; ++j) {
      std::cout << result[i][j] << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}

int** matrix_product(int a[N1][N2], int b[N2][N3]) {
  int* (*result) = new int*[N1];
  for (int i = 0; i < N1; ++i) {
    result[i] = new int[N3];
  }
  for (int i = 0; i < N1; ++i) {
    for (int j = 0 ; j < N3; ++j) {
      result[i][j] = 0;
    }
  }
  for (int i = 0; i < N1; ++i) {
    for (int j = 0; j < N3; ++j) {      
      for (int k = 0; k < N2; ++k) {
	result[i][j] += (a[i][k] * b[k][j]);
      }
    }
  }
  return result;
}
