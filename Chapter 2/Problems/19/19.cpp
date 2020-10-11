#include <iostream>

const int SIZE = 3;

int trace(int matrix[SIZE][SIZE]);

int main(int argc, char* argv[]) {
  int a[SIZE][SIZE] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
  std::cout << trace(a);
  return 0;
}

int trace(int matrix[SIZE][SIZE]) {
  int total = 0;
  for (int i = 0; i < SIZE; ++i) {
    total += matrix[i][i];
  }
  return total;
}
