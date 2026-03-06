#ifndef SHROOMTOKER_H
#define SHROOMTOKER_H

#include "IModifier.h"
#include "../ScoringSystem.h"

class ShroomToker : public IModifier {
public:
    void apply(Score &score) override
    {
        score.mult = score.mult*2;
    }

    std::string getName() override
    {
        return "Mushroom Toker (+2 mult)";
    }
};

#endif