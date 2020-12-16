#include <iostream>
#include <cmath>

double mean(double a[], int n);
double standard_deviation(double a[], int n);

int main(int argc, char* argv[]) {
  double a[] = {1, 2, 3, 4, 5};
  std::cout << standard_deviation(a, 5) << '\n';
  return 0;
}

double mean(double a[], int n) {
  double sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
  }
  return sum / n;
}

double standard_deviation(double a[], int n) {
  double m = mean(a, n);
  double sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += pow(a[i] - m, 2);
  }
  return sqrt(sum / n);
}
