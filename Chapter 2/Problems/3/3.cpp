#include <iostream>

int* append(int a[], int n1, int b[], int n2);

int main(int argc, char* argv[]) {
  int a[] = {4, 6, 2, 7, 6, 6, 8};
  int b[] = {1, 4, 9};
  int n1 = sizeof(a) / sizeof(int);
  int n2 = sizeof(b) / sizeof(int);
  int* new_arr = append(a, n1, b, n2);
  for (int i = 0; i < n1 + n2; ++i) {
    std::cout << new_arr[i] << " ";
  }
  delete [] new_arr;
  return 0;
}

int* append(int a[], int n1, int b[], int n2) {
  int* new_array = new int[n1 + n2];
  for (int i = 0; i < n1; ++i) {
    new_array[i] = a[i];
  }
  for (int i = n1; i < n1 + n2; ++i) {
    new_array[i] = b[i - n1];
  }
  return new_array;
}
