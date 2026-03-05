#include <iostream>
#include "RunSession.h"
#include "Deck.h"
#include "Card.h"

void runSession()
{
    Deck deck;
    deck.shuffle();

    std::cout << "Your hand: ";

    for (int i = 0; i < 5; i++)
    {
        Card c = deck.draw();
        std::cout << rankToString(c.rank)
                  << suitToString(c.suit)
                  << " ";
    }

    std::cout << std::endl;
}