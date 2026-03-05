#ifndef SCORINGSYSTEM_H
#define SCORINGSYSTEM_H

#include "Hand.h"
#include <string>

class ScoringSystem
{
public:
    static std::string evaluateHand(const Hand& hand);
};

#endif