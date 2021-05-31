#include <iostream>

int euclid_rec(int n1, int n2);

int euclid_rec(int n1, int n2) {
  if (!n1) {
    return n2;
  }
  else if (!n2) {
    return n1;
  }
  else if (n1 > n2) {
    return euclid_rec(n1 % n2, n2);
  }
  else {
    return euclid_rec(n1, n2 % n1);
  }
}

int main(int argc, char* argv[]) {
  std::cout << euclid_rec(385, 231) << '\n';
  return 0;
}
