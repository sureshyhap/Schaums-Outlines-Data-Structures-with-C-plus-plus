#include <iostream>

constexpr int N = 2;

int trace(int square_mat[N][N]);

int main(int argc, char* argv[]) {
  int a[N][N] = {
    {1, 2}, {3, 4}
  };
  std::cout << trace(a) << '\n';
  return 0;
}

int trace(int square_mat[N][N]) {
  int sum = 0;
  for (int i = 0; i < N; ++i) {
    sum += square_mat[i][i];
  }
  return sum;
}
