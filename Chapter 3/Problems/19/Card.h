#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

class Card {
  friend std::ostream& operator<<(std::ostream&, const Card&);
 public:
  enum Rank {
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
    JACK, QUEEN, KING, ACE
  };
  enum Suit {
    CLUB, DIAMOND, HEART, SPADE
  };
  Card(Rank = ACE, Suit = SPADE); // default constructor
  Card(int, int); // constructor
  Card(const Card&); // copy constructor
  ~Card(); // destructor
  Rank rank() const;
  Suit suit() const;
  int count() const;
  std::string to_string() const;
  std::string abbr() const;
  bool operator<(const Card&) const;
  bool operator>(const Card&) const;
  bool operator<=(const Card&) const;
  bool operator>=(const Card&) const;
  bool operator==(const Card&) const;
  bool operator!=(const Card&) const;
 private:
  Rank _rank;
  Suit _suit;
  static int _count[13][4];
};

#endif // CARD_H
