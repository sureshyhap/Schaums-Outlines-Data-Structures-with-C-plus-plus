#include <iostream>

template <typename T>
void sort(T a[], const int N);

int main(int argc, char* argv[]) {
  const int SIZE = 5;
  int a[SIZE] = {0};
  std::cout << "Enter five integers: ";
  for (int i = 0; i < SIZE; ++i) {
    std::cin >> a[i];
  }
  sort(a, SIZE);
  
  // SIZE is odd so the middle element is SIZE / 2
  std::cout << "Their median is " << a[SIZE / 2];

  return 0;
}

template <typename T>
void sort(T a[], const int N) {
  // Loop for the number of passes
  for (int i = 0; i < N; ++i) {
    bool swapped = false;
    // Loop for comparisons within one pass
    for (int j = 1; j < N - i; ++j) {
      if (a[j - 1] > a[j]) {
	T temp = a[j - 1];
	a[j - 1] = a[j];
	a[j] = temp;
	swapped = true;
      }
    }
    // If a pass is completed without swapping, the
    // array is sorted
    if (swapped == false) {
      return;
    }
  }
}
