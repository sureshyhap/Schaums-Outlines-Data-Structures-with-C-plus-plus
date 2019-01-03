#include <iostream>

bool test_sorted(int a[], int n);

int main(int argc, char* argv[]) {
  int a[] = {4, 3, 5, 2};
  int b[] = {1, 3, 4, 7};
  std::cout << test_sorted(a, 4) << std::endl;
  std::cout << test_sorted(b, 4);
  return 0;
}

bool test_sorted(int a[], int n) {
  for (int i = 1; i < n; ++i) {
    if (a[i - 1] > a[i]) {
      return false;
    }
  }
  return true;
}
