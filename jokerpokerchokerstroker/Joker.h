#ifndef JOKER_H
#define JOKER_H

#include "HandEvaluator.h"

class Joker {
public:
    virtual ~Joker() {}
    virtual void apply(int& chips, int& mult, HandType type) = 0;
};

class PairBooster : public Joker {
public:
    void apply(int& chips, int& mult, HandType type) override;
};

#endif