#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Deck.h"
#include "Joker.h"

class Game {
private:
    Deck deck;
    std::vector<Card> currentHand;
    std::vector<Joker*> jokers;

    int totalScore;

public:
    Game();
    void start();
    void playRound();
    void drawHand();
    void scoreHand();
};

#endif