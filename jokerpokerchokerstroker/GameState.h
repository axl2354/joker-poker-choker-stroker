#ifndef GAMESTATE_H
#define GAMESTATE_H

#pragma once
#include <vector>
#include "Deck.h"
#include "Hand.h"
#include "toker/IModifier.h"

struct GameState
{
    Deck deck;
    Hand hand;

    int handsRemaining;
    int discardsRemaining;

    int totalScore;
    int money;

    std::vector<IModifier*> tokers;
};

#endif