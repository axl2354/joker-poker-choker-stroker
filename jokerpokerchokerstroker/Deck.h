#ifndef DECK_H
#define DECK_H
using namespace std;
#include <vector>
#include "Card.h"

class Deck {
private:
    vector<Card> cards;

public:
    Deck();
    void shuffle();
    Card draw();
};


#endif