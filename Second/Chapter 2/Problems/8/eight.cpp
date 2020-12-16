#include <iostream>

int return_to_original(int a[], int n);
bool is_sorted(int a[], int n);
void perfect_shuffle(int a[], int n);

int main(int argc, char* argv[]) {
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
  std::cout << return_to_original(a, 8);
  return 0;
}

int return_to_original(int a[], int n) {
  int count = 0;
  do {
    perfect_shuffle(a, n);
    ++count;
  } while (!is_sorted(a, n));
  return count;
}

bool is_sorted(int a[], int n) {
  for (int i = 1; i < n; ++i) {
    if (a[i] < a[i - 1]) {
      return false;
    }
  }
  return true;
}

void perfect_shuffle(int a[], int n) {
  int b[n] = {};
  for (int i = 0, j = n / 2, k = 0; j < n; ) {
    b[k++] = a[j++];
    b[k++] = a[i++];
  }
  for (int i = 0; i < n; ++i) {
    a[i] = b[i];
  }
}
