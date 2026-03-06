#include "hand.h"
#include <iostream>
using namespace std;
void Hand::addCard(Card c)
{
    cards.push_back(c);
}

void Hand::print() const
{
    const auto& cards = getCards();

    for (int i = 0; i < cards.size(); i++)
    {
        std::cout << i << ": "
                  << rankToString(cards[i].rank)
                  << suitToString(cards[i].suit)
                  << std::endl;
    }
}


const vector<Card>& Hand::getCards() const
{
    return cards;
}
void Hand::removeCard(int index)
{
    cards.erase(cards.begin() + index);
}

int Hand::size() const
{
    return cards.size();
}