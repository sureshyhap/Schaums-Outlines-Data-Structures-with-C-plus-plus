#include <iostream>

double mean(double a[], int n);

int main(int argc, char* argv[]) {
  double a[] = {4, 6, 2, 3, 0};
  std::cout << mean(a, 5);
}

double mean(double a[], int n) {
  double total = 0;
  for (int i = 0; i < n; ++i) {
    total += a[i];
  }
  return (total / n);
}
