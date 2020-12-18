#include <iostream>
#include <vector>
#include<iomanip>

void pascals_triangle(int rows);

int main(int argc, char* argv[]) {
  pascals_triangle(13);
  return 0;
}

void pascals_triangle(int rows) {
  constexpr int WIDTH = 4;
  std::vector<int> previous_row, row;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j == 0 or j == i) {
	row.push_back(1);
	continue;
      }
      row.push_back(previous_row[j - 1] + previous_row[j]);      
    }
    previous_row = row;
    for (int k = 0; k < (rows - i) * WIDTH / 2; ++k) {
      std::cout << ' ';
    }
    int size = row.size();
    for (int k = 0; k < size; ++k) {
      std::cout << std::setw(WIDTH) << row[k];
    }
    std::cout << '\n';
    row.clear();
  }
}
