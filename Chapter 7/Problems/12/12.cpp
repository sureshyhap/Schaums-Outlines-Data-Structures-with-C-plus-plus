#include <iostream>
#include <list>

int main(int argc, char* argv[]) {
  std::cout << "Enter number of letters: ";
  int chars = 0;
  std::cin >> chars;
  std::cout << "Enter the skip number: ";
  int skip = 0;
  std::cin >> skip;
  std::list<char> circ_list;
  for (int i = 0; i < chars; ++i) {
    circ_list.push_back(char('A' + i));
  }
  std::list<char>::iterator it = circ_list.begin();
  while (circ_list.size() > 1) {
    for (int i = 0; i < skip; ++i) {
      ++it;
      if (it == circ_list.end()) {
	it = circ_list.begin();
      }
    }
    it = circ_list.erase(it);
    if (it == circ_list.end()) {
      it = circ_list.begin();
    }
  }
  std::cout << circ_list.front() << std::endl;
  return 0;
}
