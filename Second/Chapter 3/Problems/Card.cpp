#include "Card.h"

std::ostream& operator<<(std::ostream& os, const Card& c) {
  return os << c.to_string();
}

Card::Card(RANK r, SUIT s) : rank(r), suit(s) {
  ++count[r][s];
}

Card::Card(int r, int s) : rank(RANK(r)), suit(SUIT(s)) {
  ++count[r][s];
}

Card::Card(const Card& c) : rank(c.rank), suit(c.suit) {
  ++count[rank][suit];
}

Card::~Card() {
  --count[rank][suit];
}

Card& Card::operator=(const Card& c) {
  rank = c.rank;
  suit = c.suit;
  ++count[rank][suit];
  return *this;
}

Card::RANK Card::get_rank() const {
  return rank;
}

Card::SUIT Card::get_suit() const {
  return suit;
}

int Card::get_count() const {
  return count[rank][suit];
}

std::string Card::to_string() const {
  std::string r, s;
  switch (rank) {
  case TWO:
    r = "TWO";
    break;
  case THREE:
    r = "THREE";
    break;
  case FOUR:
    r = "FOUR";
    break;
  case FIVE:
    r = "FIVE";
    break;
  case SIX:
    r = "SIX";
    break;
  case SEVEN:
    r = "SEVEN";
    break;
  case EIGHT:
    r = "EIGHT";
    break;
  case NINE:
    r = "NINE";
    break;
  case TEN:
    r = "TEN";
    break;
  case JACK:
    r = "JACK";
    break;
  case QUEEN:
    r = "QUEEN";
    break;
  case KING:
    r = "KING";
    break;
  case ACE:
    r = "ACE";
    break;
  }
  switch (suit) {
  case CLUBS:
    s = "CLUBS";
    break;
  case DIAMONDS:
    s = "DIAMONDS";
    break;
  case HEARTS:
    s = "HEARTS";
    break;
  case SPADES:
    s = "SPADES";
    break;    
  }
  return r + " of " + s;
}

std::string Card::abbr() const {
  std::string a;
  switch (rank) {
  case TWO:
    a = "2";
    break;
  case THREE:
    a = "3";
    break;
  case FOUR:
    a = "4";
    break;
  case FIVE:
    a = "5";
    break;
  case SIX:
    a = "6";
    break;
  case SEVEN:
    a = "7";
    break;
  case EIGHT:
    a = "8";
    break;
  case NINE:
    a = "9";
    break;
  case TEN:
    a = "10";
    break;
  case JACK:
    a = "J";
    break;
  case QUEEN:
    a = "Q";
    break;
  case KING:
    a = "K";
    break;
  case ACE:
    a = "A";
    break;
  }
  switch (suit) {
  case CLUBS:
    a += "C";
    break;
  case DIAMONDS:
    a += "D";
    break;
  case HEARTS:
    a += "H";
    break;
  case SPADES:
    a += "S";
    break;    
  }
  return a;
}

bool Card::is_face_card() const {
  if (rank == JACK or rank == QUEEN or rank == KING or rank == ACE) {
    return true;
  }
  else {
    return false;
  }
}

bool Card::operator<(const Card& c) const {
  if (rank < c.rank or (rank == c.rank and suit < c.suit)) {
    return true;
  }
  else {
    return false;
  }
}

bool Card::operator>(const Card& c) const {
  if (rank > c.rank or (rank == c.rank and suit > c.suit)) {
    return true;
  }
  else {
    return false;
  }  
}

bool Card::operator<=(const Card& c) const {
  return not (*this > c);
}

bool Card::operator>=(const Card& c) const {
  return not (*this < c);
}

bool Card::operator!=(const Card& c) const {
  if (rank != c.rank or suit != c.suit) {
    return true;
  }
  else {
    return false;
  }
}

bool Card::operator==(const Card& c) const {
  return not (*this != c);
}

int Card::count[13][4] = {{0}};
