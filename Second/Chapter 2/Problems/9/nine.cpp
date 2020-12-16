#include <iostream>

double mean(double a[], int n);

int main(int argc, char* argv[]) {
  double a[] = {1, 2, 3, 5};
  std::cout << mean(a, 4) << '\n';
  return 0;
}

double mean(double a[], int n) {
  double sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
  }
  return sum / n;
}
