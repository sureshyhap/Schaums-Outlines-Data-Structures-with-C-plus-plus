#include <iostream>
#include <list>

template <typename T>
class SelfOrganizingList : public std::list<T> {
public:
  bool check_and_move(const T& data);
  void print() const;
};

template <typename T>
bool SelfOrganizingList<T>::check_and_move(const T& data) {
  for (auto it = this->begin(); it != this->end(); ++it) {
    if (*it == data) {
      this->push_front(data);
      this->erase(it);
      return true;
    }
  }
  return false;
}

template <typename T>
void SelfOrganizingList<T>::print() const {
  for (auto element : *this) {
    std::cout << element << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char* argv[]) {
  SelfOrganizingList<int> sol;
  sol.push_back(5);
  sol.push_back(1);
  sol.push_back(3);
  sol.push_back(7);
  sol.push_back(10);
  std::cout << sol.check_and_move(12) << std::endl;
  sol.print();
  std::cout << sol.check_and_move(7) << std::endl;
  sol.print();
  return 0;
}
