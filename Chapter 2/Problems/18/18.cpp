#include <iostream>
#include <iomanip>

int main(int argc, char* argv[]) {
  std::cout << "Enter the number of rows for Pascal's Triangle: ";
  int rows = 0;
  std::cin >> rows;
  int* previous_row = new int[rows];
  int* present_row = new int[rows];
  for (int i = 0; i <= rows; ++i) {
    previous_row[i] = 1;
    present_row[i] = 1;
  }
  for (int count = 0, j = rows; count < rows; ++count, --j) {
    for (int k = 0; k < j; ++k) {
      std::cout << "\t";
    }
    std::cout <<  1 << "\t\t";
    for (int i = 1; i < count; ++i) {
      present_row[i] = previous_row[i - 1] + previous_row[i];
    }
    for (int i = 0; i < rows; ++i) {
      previous_row[i] = present_row[i];
    }
    for (int i = 1; i < count; ++i) {
      std::cout << present_row[i] << "\t\t";
    }
    if (count != 0) {
      std::cout << 1;
    }
    std::cout << '\n';
  }
  return 0;
}
