#include <iostream>

int get_log(int num);

int main(int argc, char* argv[]) {
  std::cout << "Enter a number: ";
  int num;
  std::cin >> num;
  std::cout << "The ibl of " << num << " is " << get_log(num);
  return 0;
}

int get_log(int num) {
  int count = 0;
  while (num != 0) {
    num /= 2;
    ++count;
  }
  return count;
}
