#ifndef HAND_EVALUATOR_H
#define HAND_EVALUATOR_H

#include <vector>
#include "card.h"

enum HandType {
    HIGH_CARD,
    PAIR,
    TWO_PAIR,
    THREE_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_KIND,
    STRAIGHT_FLUSH
};

HandType evaluateHand(const std::vector<Card>& hand);
int getBaseChips(HandType type);
int getBaseMult(HandType type);

#endif