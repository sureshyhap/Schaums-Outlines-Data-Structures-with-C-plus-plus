#include "Card.h"

int Card::_count[13][4] = {{0}};

std::ostream& operator<<(std::ostream& os, const Card& c) {
  os << c.to_string();
  return os;
}

Card::Card(Rank r, Suit s) : _rank(r), _suit(s) {
  ++_count[r][s];
}

Card::Card(int a, int b) : _rank(Rank(a)), _suit(Suit(b)) {
  ++_count[a][b];
}

Card::Card(const Card& c) : _rank(c._rank), _suit(c._suit) {
  ++_count[_rank][_suit];
}

Card::~Card() {
  --_count[_rank][_suit];
}

Card::Rank Card::rank() const {
  return _rank;
}

Card::Suit Card::suit() const {
  return _suit;
}

int Card::count() const {
  return _count[_rank][_suit];
}

std::string Card::to_string() const {
  std::string s;
  switch (_rank) {
  case TWO:
    s += "Two";
    break;
  case THREE:
    s += "Three";
    break;
  case FOUR:
    s += "Four";
    break;

  case FIVE:
    s += "Five";
    break;
  case SIX:
    s += "Six";
    break;
  case SEVEN:
    s += "Seven";
    break;
  case EIGHT:
    s += "Eight";
    break;
  case NINE:
    s += "Nine";
    break;
  case TEN:
    s += "Ten";
    break;
  case JACK:
    s += "Jack";
    break;
  case QUEEN:
    s += "Queen";
    break;
  case KING:
    s += "King";
    break;
  case ACE:
    s += "Ace";
    break;
  }
  s += " of ";
  switch (_suit) {
  case CLUB:
    s += "Clubs";
    break;
  case DIAMOND:
    s += "Diamonds";
    break;
  case HEART:
    s += "Hearts";
    break;
  case SPADE:
    s += "Spades";
    break;
  }
  return s;
}

std::string Card::abbr() const {
  std::string s;
  switch (_rank) {
  case TWO:
    s += "2";
    break;
  case THREE:
    s += "3";
    break;
  case FOUR:
    s += "4";
    break;
  case FIVE:
    s += "5";
    break;
  case SIX:
    s += "6";
    break;
  case SEVEN:
    s += "7";
    break;
  case EIGHT:
    s += "8";
    break;
  case NINE:
    s += "9";
    break;
  case TEN:
    s += "10";
    break;
  case JACK:
    s += "J";
    break;
  case QUEEN:
    s += "Q";
    break;
  case KING:
    s += "K";
    break;
  case ACE:
    s += "A";
    break;    
  }
  switch (_suit) {
  case CLUB:
    s += "C";
    break;
  case DIAMOND:
    s += "D";
    break;
  case HEART:
    s += "H";
    break;
  case SPADE:
    s += "S";
    break;
  }
  return s;
}

bool Card::operator<(const Card& c) const {
  return _rank < c._rank || (_rank == c._rank && _suit < c._suit);
}

bool Card::operator>(const Card& c) const {
  return _rank > c._rank || (_rank == c._rank && _suit > c._suit);
}

bool Card::operator<=(const Card& c) const {
  return _rank < c._rank || (_rank == c._rank && _suit <= c._suit);
}

bool Card::operator>=(const Card& c) const {
  return _rank > c._rank || (_rank == c._rank && _suit >= c._suit);
}

bool Card::operator==(const Card& c) const {
  return _rank == c._rank && _suit == c._suit;
}

bool Card::operator!=(const Card& c) const {
  return _rank != c._rank || _suit != c._suit;
}

