#include <iostream>

constexpr int N = 3;

void transpose(int square_mat[N][N]);

int main(int argc, char* argv[]) {
  int a[N][N] = {
    {1, 2, 3}, {4, 5, 6}, {7, 8, 9}
  };
  transpose(a);
  for (auto& rows : a) {
    for (auto elem : rows) {
      std::cout << elem << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}

void transpose(int square_mat[N][N]) {
  int aux[N][N] = {{}};
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      aux[j][i] = square_mat[i][j];
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      square_mat[i][j] = aux[i][j];
    }
  }
}
