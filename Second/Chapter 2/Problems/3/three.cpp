#include <iostream>

int* append(int a[], int n1, int b[], int n2);

int main(int argc, char* argv[]) {
  int a[] = {4, 1, 7, 3, 6, 2};
  int b[] = {1, 8, 3, 6, 2, 1, 6};
  int size_a = sizeof(a) / sizeof(int);
  int size_b = sizeof(b) / sizeof(int);
  int* final_array = append(a, size_a, b, size_b);
  for (int* p = final_array; p != final_array + size_a + size_b; ++p) {
    std::cout << *p << ' ';
  }
  std::cout << '\n';
  return 0;
}

int* append(int a[], int n1, int b[], int n2) {
  int* p = new int[n1 + n2];
  for (int i = 0; i < n1; ++i) {
    p[i] = a[i];
  }
  for (int i = 0; i < n2; ++i) {
    p[n1 + i] = b[i];
  }
  return p;
}
