#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Deck.h"
#include "Hand.h"

struct GameState
{
    Deck deck;
    Hand hand;

    int handsRemaining;
    int discardsRemaining;

    int totalScore;
};

#endif