#include "ModifierFactory.h"
#include "toker/Toker.h"
#include "toker/ShroomToker.h"
#include <cstdlib>

IModifier* ModifierFactory::createModifier(int type) {
    switch(type) {
        case 1: return new Toker();
        case 2: return new ShroomToker();
        default: return nullptr;
    }
}
IModifier* ModifierFactory::createRandom()
{
    int r = rand() % 2;

    if (r == 0)
        return new Toker();

    return new ShroomToker();
}