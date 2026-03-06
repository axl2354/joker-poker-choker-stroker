#ifndef MODIFIERFACTORY_H
#define MODIFIERFACTORY_H

#include "toker/IModifier.h"

class ModifierFactory {
public:
    static IModifier* createModifier(int type);
    static IModifier* createRandom();
};

#endif