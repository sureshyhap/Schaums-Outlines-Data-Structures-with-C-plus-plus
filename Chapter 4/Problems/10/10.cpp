#include <iostream>

void reverse(std::string s, int length);

int main(int argc, char* argv[]) {
  reverse("reverse", 7);
  return 0;
}

void reverse(std::string s, int length) {
  if (length == 0) {
    return;
  }
  std::cout << s[length - 1];
  reverse(s, length - 1);
}
