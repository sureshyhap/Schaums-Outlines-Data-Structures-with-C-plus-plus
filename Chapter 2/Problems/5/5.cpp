#include <iostream>

void rotate(int a[], int n, int rotate_num);

int main(int argc, char* argv[]) {
  int a[] = {3, 1, 2, 5, 7};
  rotate(a, 5, 2);
  for (int i = 0; i < 5; ++i) {
    std::cout << a[i] << " ";
  }
  return 0;
}

void rotate(int a[], int n, int rotate_num) {
  int temp[n] = {0};
  // Rotatations greater than or equal to the size
  // are the same as a certain rotation less than the size
  rotate_num %= n;
  // Pull the last elements to the front
  for (int i = n - rotate_num, j = 0; i < n; ++i, ++j) {
    temp[j] = a[i];
  }
  // Push the first elements after the elements above
  for (int i = 0, j = rotate_num; i <= rotate_num; ++i, ++j) {
    temp[j] = a[i];
  }
  // Copy to original array
  for (int i = 0; i < n; ++i) {
    a[i] = temp[i];
  }
}
