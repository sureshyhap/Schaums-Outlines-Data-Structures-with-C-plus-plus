#include <iostream>
#include <cmath>

double mean(double a[], int n);
double sd(double a[], int n);

int main(int argc, char* argv[]) {
  double a[] = {5, 4, 1, 3, 7, 4};
  std::cout << sd(a, 6);
}

double mean(double a[], int n) {
  double total = 0;
  for (int i = 0; i < n; ++i) {
    total += a[i];
  }
  return (total / n);
}

double sd(double a[], int n) {
  double m = mean(a, n);
  double total = 0;
  for (int i = 0; i < n; ++i) {
    total += pow((a[i] - m), 2);
  }
  return sqrt(total) / n;
}
