#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"
using namespace std;

class Hand {
private:
    vector<Card> cards;
public:
    void addCard(Card c);
    void print() const;
const vector<Card>& getCards() const;
};

#endif