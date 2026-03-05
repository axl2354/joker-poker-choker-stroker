#include <iostream>
#include "RunSession.h"
#include "Deck.h"
#include "Card.h"
#include "hand.h"
#include "ScoringSystem.h"
using namespace std;

void runSession()
{
    Deck deck;
    deck.shuffle();

    Hand hand;
    Hand playedHand;
    for (int i = 0; i < 8; i++)
    {
        hand.addCard(deck.draw());
    }
    cout << "Your hand:\n";
    hand.print();

    std::cout << "Choose 5 cards to play (enter indexes):\n";

    for (int i = 0; i < 5; i++)
    {
        int index;
        std::cin >> index;

        playedHand.addCard(hand.getCards()[index]);
    }

    

    
    string result = ScoringSystem::evaluateHand(hand);

    std::cout << "Played Hand: ";
    playedHand.print();

    cout << "Hand Type: " << result << endl;
}
