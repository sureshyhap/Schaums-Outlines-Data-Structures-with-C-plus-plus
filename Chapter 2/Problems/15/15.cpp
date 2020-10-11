#include <iostream>
#include <string>

std::string** duplicate(std::string* a[], int n);

int main(int argc, char* argv[]) {
  std::string* a[5];
  std::string first = "Hello";
  std::string second = "World";
  std::string third= "How";
  std::string fourth = "are";
  std::string fifth = "you?";
  a[0] = &first;
  a[1] = &second;
  a[2] = &third;
  a[3] = &fourth;
  a[4] = &fifth;
  std::string** p_str = duplicate(a, 5);
  for (int i = 0; i < 5; ++i) {
    std::cout << *p_str[i] << " ";
    delete p_str[i];
  }
  delete [] p_str;
  return 0;
}

std::string** duplicate(std::string* a[], int n) {
  std::string* (*p) = new std::string*[n];
  for (int i = 0; i < n; ++i) {
    p[i] = new std::string(*a[i]);
  }
  return p;
}
