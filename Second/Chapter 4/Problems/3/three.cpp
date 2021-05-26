#include <iostream>

int sum_n_array(const int* const arr, int n);

int sum_n_array(const int* const arr, int n) {
  if (n == 1) {
    return arr[0];
  }
  return arr[n - 1] + sum_n_array(arr, n - 1);
}

int main(int argc, char* argv[]) {
  int a[] = {1, 2, 3, 4, 5};
  std::cout << sum_n_array(a, 5) << '\n';
  return 0;
}
