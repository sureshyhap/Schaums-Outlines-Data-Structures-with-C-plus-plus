#include <iostream>

int* merge(int a[], int n1, int b[], int n2);

int main(int argc, char* argv[]) {
  int a[] = {1, 3, 5, 7, 8};
  int b[] = {2, 4, 6, 7, 9};
  int* c = merge(a, 5, b, 5);
  for (int i = 0; i < 10; ++i) {
    std::cout << c[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}

int* merge(int a[], int n1, int b[], int n2) {
  int size = n1 + n2;
  int* c = new int[size];
  for (int i = 0, j = 0, k = 0; i < size; ++i) {
    if (j == n1) {
      c[i] = b[k++];
      continue;
    }
    else if (k == n2) {
      c[i] = a[j++];
      continue;
    }
    if (a[j] < b[k]) {
      c[i] = a[j++];
    }
    else {
      c[i] = b[k++];
    }
  }
  return c;
}
