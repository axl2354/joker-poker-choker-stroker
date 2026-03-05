#include "Card.h"

std::string rankToString(int rank) {
    if (rank <= 10) return std::to_string(rank);
    if (rank == 11) return "J";
    if (rank == 12) return "Q";
    if (rank == 13) return "K";
    if (rank == 14) return "A";
    return "?";
}

std::string suitToString(Suit suit) {
    switch (suit) {
        case HEARTS: return "H";
        case DIAMONDS: return "D";
        case CLUBS: return "C";
        case SPADES: return "S";
    }
    return "?";
}