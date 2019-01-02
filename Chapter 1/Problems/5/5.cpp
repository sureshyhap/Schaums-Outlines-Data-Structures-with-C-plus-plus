#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[]) {
  enum Hand {
	     ROCK, PAPER, SCISSORS
  };
  std::cout << "Choose a hand (Rock = 0, Paper = 1, Scissors = 2)\n";
  int player_hand;
  std::cin >> player_hand;
  int computer_hand;
  unsigned seed = time(NULL);
  srand(seed);
  computer_hand = (rand() / 100) % 3;
  switch (player_hand) {
  case ROCK:
    switch (computer_hand) {
    case ROCK:
      std::cout << "Computer chose Rock. Tie." << std::endl;
      break;
    case PAPER:
      std::cout << "Computer chose Paper. Computer wins!" << std::endl;
      break;
    case SCISSORS:
      std::cout << "Computer chose Scissors. Player wins!" << std::endl;
    }
    break;
  case PAPER:
    switch (computer_hand) {
    case ROCK:
      std::cout << "Computer chose Rock. Player wins!" << std::endl;
      break;
    case PAPER:
      std::cout << "Computer chose Paper. Tie." << std::endl;
      break;
    case SCISSORS:
      std::cout << "Computer chose Scissors. Computer wins!" << std::endl;
    }
    break;
  case SCISSORS:
    switch (computer_hand) {
    case ROCK:
      std::cout << "Computer chose Rock. Computer wins!" << std::endl;
      break;
    case PAPER:
      std::cout << "Computer chose Paper. Player wins!" << std::endl;
      break;
    case SCISSORS:
      std::cout << "Computer chose Scissors. Tie." << std::endl;
    }
    break;
  }
  return 0;
}
