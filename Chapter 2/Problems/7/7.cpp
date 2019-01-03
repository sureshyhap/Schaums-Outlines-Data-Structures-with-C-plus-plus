#include <iostream>

void perfect_shuffle(int a[], int n);

int main(int argc, char* argv[]) {
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
  perfect_shuffle(a, 8);
  for (int i = 0; i < 8; ++i) {
    std::cout << a[i] << " ";
  }
  return 0;
}

// Assumes n is even
void perfect_shuffle(int a[], int n) {
  int b[n / 2] = {0};
  int c[n / 2] = {0};
  for (int i = 0; i < n / 2; ++i) {
    c[i] = a[i + n / 2];
  }
  for (int i = 0; i < n / 2; ++i) {
    b[i] = a[i];
  }
  for (int i = 0, j = 0, k = 0; i < n; ++i) {
    if (i % 2 == 0) {
      a[i] = c[j++];
    }
    else {
      a[i] = b[k++];
    }
  }
}
