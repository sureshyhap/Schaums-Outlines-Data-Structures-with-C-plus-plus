#include <iostream>
#include <string>
#include <cctype>

bool is_palindrome(const std::string& phrase);
std::string filter(const std::string& sentence);

int main(int argc, char* argv[]) {
  std::cout << is_palindrome("Able was I, ere I saw elba.") << '\n';
  return 0;
}

std::string filter(const std::string& sentence) {
  std::string output;
  int size = sentence.size();
  for (int i = 0; i < size; ++i) {
    if (!isalpha(sentence[i])) {
      continue;
    }
    output.push_back(toupper(sentence[i]));
  }
  return output;
}

bool is_palindrome(const std::string& sentence) {
  std::string phrase = filter(sentence);
  int size = phrase.size();
  for (int i = 0; i < size / 2; ++i) {
    if (phrase[i] != phrase[size - 1 - i]) {
      return false;
    }
  }
  return true;
}
