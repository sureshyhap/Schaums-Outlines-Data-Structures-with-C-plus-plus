#include <iostream>

void add_elements(int a[], int b[], int result[], int n);

int main(int argc, char* argv[]) {
  int a[5] = {4, 1, 6, 3, 2};
  int b[5] = {1, 4, 3, 4, 4};
  int c[5] = {};
  add_elements(a, b, c, 5);
  for (int i = 0; i < 5; ++i) {
    std::cout << c[i] << " ";
  }
  return 0;
}

void add_elements(int a[], int b[], int result[], int n) {
  for (int i = 0; i < n; ++i) {
    result[i] = a[i] + b[i];
  }
}
