#include <iostream>
#include <vector>

template <typename T>
inline void swap(T& first, T& second);

template <typename T>
T quick_select(std::vector<T>& v, int left, int right, int k) {
 beginning:
  if (left == right) {
    return v.at(left);
  }
  T pivot = {v.at(k)};
  swap(v.at(k), v.at(right));
  int i = {left - 1}, j = {right};
  while (i < j) {
    while (v.at(++i) < pivot) {
      ;
    }
    while (j >= i and v.at(--j) > pivot) {
      ;
    }
    if (i < j) {
      swap(v.at(i), v.at(j));
    }
  }
  swap(v.at(i), v.at(right));
  if (i == k) {
    return v.at(i);
  }
  else if (i < k) {
    //    quick_select(v, i + 1, right, k);
    left = {i + 1};
    goto beginning;
  }
  else {
    //    quick_select(v, left, i - 1, k);
    right = {i - 1};
    goto beginning;
  }
}

int main(int argc, char* argv[]) {
  std::cout << "Enter five integers: ";
  int a[5] = {};
  for (auto& elem : a) {
    std::cin >> elem;
  }
  std::vector<int> v(std::begin(a), std::end(a));
  std::cout << quick_select(v, 0, v.size() - 1, 2);
  return 0;
}

template <typename T>
inline void swap(T& first, T& second) {
  T temp = first;
  first = second;
  second = temp;
}
