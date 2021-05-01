#include <iostream>
#include "../Card.h"

int main(int argc, char* argv[]) {
  Card card(Card::RANK::FIVE, Card::SUIT::HEARTS);
  std::cout << card << '\n';
  Card card2(12, 3);
  std::cout << card2 << '\n';
  {
  Card card3(card);
  std::cout << card3 << '\n';
  card3 = card2;
  std::cout << card3 << '\n';
  std::cout << card3.get_rank() << '\n';
  std::cout << card3.get_suit() << '\n';
  std::cout << card2.get_count() << '\n';
  }
  std::cout << card2.get_count() << '\n';
  std::cout << card2.abbr() << '\n';
  std::cout << std::boolalpha << card.is_face_card() << '\n';
  std::cout << card2.is_face_card() << '\n';
  std::cout << (card < card2) << '\n';
  std::cout << (card > card2) << '\n';
  std::cout << (card <= card2) << '\n';
  std::cout << (card >= card2) << '\n';
  std::cout << (card != card) << '\n';
  std::cout << (card == card) << '\n';
  return 0;
}
