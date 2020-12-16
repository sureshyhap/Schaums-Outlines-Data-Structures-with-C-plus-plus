#include <iostream>

void perfect_shuffle(int a[], int n);

int main(int argc, char* argv[]) {
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
  perfect_shuffle(a, 8);
  for (auto elem : a) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
  return 0;
}

void perfect_shuffle(int a[], int n) {
  int b[n] = {};
  for (int i = 0, j = n / 2, k = 0; j < n; ) {
    b[k++] = a[j++];
    b[k++] = a[i++];
  }
  for (int i = 0; i < n; ++i) {
    a[i] = b[i];
  }
}
