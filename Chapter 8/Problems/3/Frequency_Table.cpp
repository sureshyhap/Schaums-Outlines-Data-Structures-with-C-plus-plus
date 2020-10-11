#include "Frequency_Table.h"

std::istream& operator>>(std::istream& is, Frequency_Table& ft) {
  std::string s;
  std::vector<std::string> word_array;
  while (getline(is, s)) {
    word_array = ft.parse_line(s);
    int len = word_array.size();
    for (int i = 0; i < len; ++i) {
      ++ft.word_freqs[word_array[i]];
    }
  }
}

std::ostream& operator<<(std::ostream& os, const Frequency_Table& ft) {
  for (std::map<std::string, int>::const_iterator it = ft.word_freqs.begin(); it != ft.word_freqs.end(); ++it) {
    os << it->first << ": " << it->second << '\n';
  }
  return os;
}

Frequency_Table::Frequency_Table() {
  word_freqs = std::map<std::string, int>();
}

std::vector<std::string> Frequency_Table::parse_line(std::string line) {
  std::vector<std::string> word_array = std::vector<std::string>();
  int len = line.length();
  int i = 0;
  // Skips whitespace at the start
  while (true) {
    for (; i < len && !isalpha(line[i]); ++i) {
      ;
    }
    if (i == len) {
      break;
    }
    std::ostringstream oss;
    while (isalpha(line[i])) {
      oss << line[i];
      ++i;
    }
    word_array.push_back(oss.str());
  }
  return word_array;
}
