#include <iostream>
#include <string>

void reverse(std::string** a, int n);

int main(int argc, char* argv[]) {
  std::string h = "Hello", w = "World";
  std::string* a[] = {&h, &w};
  reverse(a, 2);
  for (int i = 0; i < 2; ++i) {
    std::cout << *(a[i]) << ' ';
  }
  std::cout << '\n';
  return 0;
}

void reverse(std::string** a, int n) {
  std::string* temp[n] = {};
  for (int i = 0; i < n; ++i) {
    temp[i] = a[n - 1 - i];
  }
  for (int i = 0; i < n; ++i) {
    a[i] = temp[i];
  }
}
