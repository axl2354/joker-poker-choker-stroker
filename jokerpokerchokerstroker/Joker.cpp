#include "Joker.h"

void PairBooster::apply(int& chips, int& mult, HandType type) {
    if (type == PAIR) {
        mult += 2;
    }
}