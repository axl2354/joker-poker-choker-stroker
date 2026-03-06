#ifndef TOKER_H
#define TOKER_H

#include "IModifier.h"
#include "../ScoringSystem.h"

class Toker : public IModifier {
public:
    void apply(Score &score) override
    {
        score.chips += 20;
    }

    std::string getName() override
    {
        return "Weed Toker (+20 chips)";
    }
};

#endif