#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

class Card {
  friend std::ostream& operator<<(std::ostream& os, const Card& c); /////////////////
 public:
  enum RANK {
	     TWO, THREE, FOUR, FIVE, SIX, SEVEN,
	     EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
  };
  enum SUIT {
	     CLUBS, DIAMONDS, HEARTS, SPADES
  };
  Card(RANK r = ACE, SUIT s = SPADES); ////////////////////
  Card(int r, int s); ////////////////////
  Card(const Card& c); ////////////////////////
  ~Card(); //////////////////
  Card& operator=(const Card& c); //////////////////
  RANK get_rank() const; ///////////////
  SUIT get_suit() const; ///////////////
  int get_count() const; /////////////////
  std::string to_string() const; ////////////////////
  std::string abbr() const; /////////////////
  bool is_face_card() const; //////////////////
  bool operator<(const Card& c) const;
  bool operator>(const Card& c) const;
  bool operator<=(const Card& c) const;
  bool operator>=(const Card& c) const;
  bool operator!=(const Card& c) const;
  bool operator==(const Card& c) const;
 private:
  RANK rank;
  SUIT suit;
  static int count[13][4];
};

#endif // CARD_H
