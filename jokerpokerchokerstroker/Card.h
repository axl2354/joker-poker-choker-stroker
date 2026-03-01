#ifndef CARD_H
#define CARD_H

#include <string>
enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
enum Mod { EMPTY };
enum Sticker { BLANK };

struct Card {
    int rank;     
    Suit suit;
    Sticker sticker;
    Mod mod;
};
std::string rankToString(int rank);
std::string suitToString(Suit suit);

#endif