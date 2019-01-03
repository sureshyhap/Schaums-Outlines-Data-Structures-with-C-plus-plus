#include <iostream>

int* merge(int a[], int n, int b[], int m);

int main(int argc, char* argv[]) {
  int a[] = {1, 2, 4, 6, 8};
  int b[] = {1, 3, 4, 5, 9, 11};
  int* new_a = merge(a, 5, b, 6);
  for (int i = 0; i < (5 + 6); ++i) {
    std::cout << new_a[i] << " ";
  }
  delete [] new_a;
  return 0;
}

int* merge(int a[], int n, int b[], int m) {
  int* new_array = new int[n + m];
  for (int i = 0, j = 0; (i + j) < (n + m); ) {
    // If a has been exhausted
    if (i == n) {
      goto the_rest_are_in_b;
    }
    // If b has been exhausted
    if (j == m) {
      goto the_rest_are_in_a;
    }
    if (a[i] < b[j]) {
    the_rest_are_in_a: new_array[i + j] = a[i];
      ++i;
    }
    else if (b[j] <= a[i]) {
    the_rest_are_in_b: new_array[i + j] = b[j];
      ++j;
    }
  }
  return new_array;
}
