#include <iostream>

int max(const int* const arr, int start, int end);

int max(const int* const arr, int start, int end) {
  if (start == end) {
    return arr[start];
  }
  int center = (start + end) / 2;
  int max1 =  max(arr, start, center);
  int max2 = max(arr, center + 1, end);
  return max1 > max2 ? max1 : max2;
}

int main(int argc, char* argv[]) {
  int a[] = {4, 1, 6, 2, 5, 6, 2, 5, 8, 4};
  int size = sizeof(a) / sizeof(int);
  std::cout << max(a, 0, size - 1) << '\n';
  return 0;
}
