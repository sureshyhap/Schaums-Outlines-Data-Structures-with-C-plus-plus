#include <iostream>

int* add_arrays(int a[], int b[], int size);

int main(int argc, char* argv[]) {
  int a[] = {3, 7, 5, 4, 3, 6, 1};
  int b[] = {6, 3, 6, 1, 3, 5, 7};
  int* sum = add_arrays(a, b, 7);
  for (int* p = sum; p != sum + 7; ++p) {
    std::cout << *p << ' ';
  }
  std::cout << '\n';
  
  return 0;
}

int* add_arrays(int a[], int b[], int size) {
  int* sum = new int[size];
  for (int i = 0; i < size; ++i) {
    sum[i] = a[i] + b[i];
  }
  return sum;
}
