#include <iostream>

int max(int a[], int start, int n);

int main(int argc, char* argv[]) {
  int a[] = {1, 4, 6, 3, 7, 5, 8, 9, 6, 5, 10, 8};
  std::cout << max(a, 0, 12);
  return 0;
}

int max(int a[], int start, int n) {
  if (n == 1) {
    return a[start];
  }
  int max1 = max(a, start, n / 2);
  int max2 = max(a, start + (n / 2), n - (n / 2));
  return  max1 > max2 ? max1 : max2;
}
