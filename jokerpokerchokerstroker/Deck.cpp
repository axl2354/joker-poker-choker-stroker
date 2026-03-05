#include "Deck.h"
#include <algorithm>
#include <random>

Deck::Deck() {
    for (int s = 0; s < 4; s++) {
        for (int r = 2; r <= 14; r++) {
            cards.push_back({r, (Suit)s});
        }
    }
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

Card Deck::draw() {
    Card c = cards.back();
    cards.pop_back();
    return c;
}



