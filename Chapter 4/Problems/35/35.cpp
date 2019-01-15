#include <iostream>

double polynomial(double x, int a[], const int n, int temp);

int main(int argc, char* argv[])  {
  int a[] = {2, 5, 3, 6};
  const int n = 4;
  std::cout << polynomial(3.4, a, n, n);
  return 0;
}

double polynomial(double x, int a[], const int n, int temp) {
  if (temp == 1) {
    return a[n - 1];
  }
  return a[n - temp] + x * (polynomial(x, a, n, temp - 1));
}

