#include <iostream>

int get_max_4(int a, int b, int c, int d);

int main(int argc, char* argv[]) {
  int a[4] = {0};
  std::cout << "Enter four integers: ";
  for (int i = 0; i < 4; ++i) {
    std::cin >> a[i];
  }
  int max = get_max_4(a[0], a[1], a[2], a[3]);
  std::cout << "Their maximum is " << max << std::endl;
  
  return 0;
}

int get_max_4(int a, int b, int c, int d) {
  if (a > b) {
    if (a > c) {
      if (a > d) {
	return a;
      }
      else {
	return d;
      }
    }
    else {
      if (c > d) {
	return c;
      }
      else {
	return d;
      }
    }
  }
  else {
    if (b > c) {
      if (b > d) {
	return b;
      }
      else {
	return d;
      }
    }
    else {
      if (c > d) {
	return c;
      }
      else {
	return d;
      }
    }
  }
}
