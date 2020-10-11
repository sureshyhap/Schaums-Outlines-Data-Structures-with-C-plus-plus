#include <iostream>

int main(int argc, char* argv[]) {
  int a[] = {44, 77, 55, 99, 66, 33, 22, 88, 77};
  int size = sizeof(a) / sizeof(int);
  for (int i = 0; i < size; ++i) {
    bool swapped = false;
    for (int j = 1; j < size - i; ++j) {
      if (a[j - 1] > a[j]) {
	int temp = a[j];
	a[j] = a[j - 1];
	a[j - 1] = temp;
	swapped = true;
      }
    }
    if (swapped == false) {
      break;
    }
  }
  for (int i = 0; i < size; ++i) {
    std::cout << a[i] << " ";
  }
  return 0;
}
