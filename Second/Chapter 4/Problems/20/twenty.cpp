#include <iostream>

int euclid_iter(int n1, int n2);

int euclid_iter(int n1, int n2) {
  while (n1 != 0 and n2 != 0) {
    if (n1 > n2) {
      n1 = n1 % n2;
    }
    else {
      n2 = n2 % n1;
    }
  }
  if (!n1) {
    return n2;
  }
  else {
    return n1;
  }
}

int main(int argc, char* argv[]) {
  std::cout << euclid_iter(385, 231) << '\n';
  return 0;
}
