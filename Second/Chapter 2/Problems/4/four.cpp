#include <iostream>

int* add_arrays(int a[], int b[], int size);

int main(int argc, char* argv[]) {
  int a
  
  return 0;
}

int* add_arrays(int a[], int b[], int size) {
  int* sum = new int[size];
  for (int i = 0; i < size; ++i) {
    sum[i] = a[i] + b[i];
  }
  return sum;
}
