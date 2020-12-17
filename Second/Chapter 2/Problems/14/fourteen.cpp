#include <iostream>
#include <string>

std::string** duplicate(std::string** a, int n);

int main(int argc, char* argv[]) {
  std::string s1 = "Hello", s2 = "There", s3 = "Guys";
  std::string* a[] = {&s1, &s2, &s3};
  std::string** copy = duplicate(a, 3);
  for (int i = 0; i < 3; ++i) {
    std::cout << *(copy[i]) << '\n';
  }
  return 0;
}

std::string** duplicate(std::string** a, int n) {
  std::string* (*s) = new std::string*[n];
  for (int i = 0; i < n; ++i) {
    s[i] = a[i];
  }
  return s;
}
