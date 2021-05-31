#include <iostream>
#include <string>

char print(std::string s, int num);
int factorial(int n);

char print(std::string s, int num) {
  /*
  //  static int length = num;
  //  static std::string s3 = s;
  if (num == 1) {
    return s[0];
  }
  for (int j = 0; j < num; ++j) {
    for (int i = 0; i < factorial(num - 1); ++i) {
      //      std::cout << s[i];
      std::string s2 = s;
      std::cout << s[j] << print(s2.erase(j, 1), num - 1);
    }
    std::cout << '\n';
  }
  */
}

int factorial(int n) {
  int result = 1;
  for (int i = 2; i <= n; ++i) {
    result *= i;
  }
  return result;
}

int main(int argc, char* argv[]) {
  print("ABC", 3);
  return 0;
}
