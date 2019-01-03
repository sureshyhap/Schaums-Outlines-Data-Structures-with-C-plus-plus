#include <iostream>
#include <string>

void reverse(std::string* a[], int n);

int main(int argc, char* argv[]) {
  std::string* arr[5];
  (arr[0]) = new std::string("Hello");
  (arr[1]) = new std::string("World");
  (arr[2]) = new std::string("How");
  (arr[3]) = new std::string("are");
  (arr[4]) = new std::string("you?");
  reverse(arr, 5);
  for (int i = 0; i < 5; ++i) {
    std::cout << *arr[i] << " ";
    delete arr[i];
  }
  return 0;
}

void reverse(std::string* a[], int n) {
  std::string* b[n];
  for (int i = 0; i < n; ++i) {
    b[i] = a[n - i - 1];
  }
  for (int i = 0; i < n; ++i) {
    a[i] = b[i];
  }
}
