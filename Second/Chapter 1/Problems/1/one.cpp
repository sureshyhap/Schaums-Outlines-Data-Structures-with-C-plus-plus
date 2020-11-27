#include <iostream>

int main(int argc, char* argv[]) {
  std::cout << "Enter four integers: ";
  int a[4] = {};
  int length = sizeof(a) / sizeof(int);
  for (int i = {0}; i < length; ++i) {
    std::cin >> a[i];
  }
  int max = {a[0]};
  for (auto elem : a) {
    if (elem > max) {
      max = elem;
    }
  }
  std::cout << "Their maximum is " << max << '\n';
  return 0;
}
