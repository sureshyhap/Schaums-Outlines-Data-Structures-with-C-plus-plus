#include <iostream>

bool is_sorted(int a[], int n);

int main(int argc, char* argv[]) {
  int a[] = {4, 1, 6, 3, 7};
  int b[] = {1, 4, 6, 7, 9};
  std::cout << std::boolalpha << is_sorted(a, 5) << '\n';
  std::cout << std::boolalpha << is_sorted(b, 5) << '\n';
  return 0;
}

bool is_sorted(int a[], int n) {
  for (int i = 1; i < n; ++i) {
    if (a[i] < a[i - 1]) {
      return false;
    }
  }
  return true;
}
