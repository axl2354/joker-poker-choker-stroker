#ifndef CARD_H
#define CARD_H
using namespace std;
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
string rankToString(int rank);
string suitToString(Suit suit);

#endif