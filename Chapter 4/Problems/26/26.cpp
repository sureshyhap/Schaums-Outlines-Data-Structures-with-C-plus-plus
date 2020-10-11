#include <iostream>

int fact(int n);

int main(int argc, char* argv[]) {
  std::cout << fact(13); // Incorrect for 13 or higher
  return 0;
}

int fact(int n) {
  if (n == 0) {
    return 1;
  }
  return n * fact(n - 1);
}
