#include <iostream>
#include <cmath>

int main(int argc, char* argv[]) {
  constexpr int N = 1000;
  bool p[N] = {false};
  p[2] = true;
  for (int i = 3; i < N; i += 2) {
    for (int j = 3; j <= sqrt(i); j += 2) {
      if (i % j == 0) {
	goto end;
      }
    }
    p[i] = true;
  end:
    ;
  }
  for (int i = 0; i < 30; ++i) {
    std::cout << i << ": " << std::boolalpha << p[i] << '\n';
  }
  return 0;
}
