#include <iostream>
#include <string>

std::string** new_duplicate(std::string** a, int n);

int main(int argc, char* argv[]) {
  std::string s1 = "Hello", s2 = "There", s3 = "Guys";
  std::string* original[] = {&s1, &s2, &s3};
  std::string** second = new_duplicate(original, 3);
  for (int i = 0; i < 3; ++i) {
    std::cout << *(second[i]) << '\n';
  }
  std::cout << '\n';
  return 0;
}

std::string** new_duplicate(std::string** a, int n) {
  std::string* (*asp) = new std::string*[n];
  for (int i = 0; i < n; ++i) {
    asp[i] = new std::string(*(a[i]));
  }
  return asp;
}
