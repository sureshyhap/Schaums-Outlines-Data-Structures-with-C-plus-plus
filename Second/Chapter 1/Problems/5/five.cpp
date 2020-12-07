#include <iostream>
#include <cstdlib>
#include <ctime>

enum Hand {
  ROCK, PAPER, SCISSORS
};

// -1 means lose, 0 means tie, 1 means win
int play_rock_paper_scissors(Hand hand);

int main(int argc, char* argv[]) {
  int hand_int = {};
  do {
    std::cout << "Choose a hand (ROCK = 0, PAPER = 1, SCISSORS = 2): ";
    std::cin >> hand_int;
  } while (hand_int != ROCK and hand_int != PAPER and hand_int != SCISSORS);
  Hand hand = static_cast<Hand>(hand_int);
  int result = play_rock_paper_scissors(hand);
  if (result == -1) {
    std::cout << "Computer wins!\n";
  }
  else if (result == 1) {
    std::cout << "You win!\n";
  }
  else {
    std::cout << "It's a tie!\n";
  }
  return 0;
}

int play_rock_paper_scissors(Hand hand) {
  unsigned int seed = time(NULL);
  srand(seed);
  Hand comp_hand = static_cast<Hand>(rand() % 3);
  switch (comp_hand) {
  case ROCK:
    std::cout << "Computer chose rock\n";
    if (hand == ROCK) {
      return 0;
    }
    else if (hand == PAPER) {
      return 1;
    }
    else {
      return -1;
    }
    break;
  case PAPER:
    std::cout << "Computer chose paper\n";
    if (hand == ROCK) {
      return -1;
    }
    else if (hand == PAPER) {
      return 0;
    }
    else {
      return 1;
    }
    break;
  case SCISSORS:
    std::cout << "Computer chose scissors\n";
    if (hand == ROCK) {
      return 1;
    }
    else if (hand == PAPER) {
      return -1;
    }
    else {
      return 0;
    }
    break;
  }
}
