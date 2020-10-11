#ifndef FREQUENCY_TABLE_H
#define FREQUENCY_TABLE_H

#include <map>
#include <string>
#include <iostream>
#include <cctype>
#include <sstream>
#include <vector>

class Frequency_Table {
  friend std::istream& operator>>(std::istream& is, Frequency_Table& ft);
  friend std::ostream& operator<<(std::ostream& os, const Frequency_Table& ft);
public:
  Frequency_Table();
protected:
  // List of words along with their frequencies
  std::map<std::string, int> word_freqs;
  // Reads in a line and outputs an array of words
  std::vector<std::string> parse_line(std::string line);
};

#endif // FREQUENCY_TABLE_H
