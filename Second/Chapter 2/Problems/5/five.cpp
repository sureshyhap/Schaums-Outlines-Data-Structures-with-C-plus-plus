#include <iostream>

void rotate(int a[], int size, int n);

int main(int argc, char* argv[]) {
  int a[] = {1, 6, 7, 3, 6, 8, 3, 5, 1};
  int size = sizeof(a) / sizeof(int);
  rotate(a, size, 3);
  for (auto elem : a) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
  return 0;
}

void rotate(int a[], int size, int n) {
  int b[size] = {};
  int i = 0;
  for (int j = size - n; j < size; ++i, ++j) {
    b[i] = a[j];
  }
  for (int j = 0; i < size; ++i, ++j) {
    b[i] = a[j];
  }
  for (int j = 0;j < size; ++j) {
    a[j] = b[j];
  }
}
