#include "ScoringSystem.h"
#include <map>
#include <algorithm>
using namespace std;

string ScoringSystem::evaluateHand(const Hand &hand)
{
    map<int, int> rankCount;

    const vector<Card> &cards = hand.getCards();

    for (const Card &c : cards)
    {
        rankCount[c.rank]++;
    }

    int pairs = 0;
    bool three = false;
    bool four = false;
    bool flush = true;
    Suit firstSuit = cards[0].suit;

    for (const Card &c : cards)
    {
        if (c.suit != firstSuit)
        {
            flush = false;
            break;
        }
    }
    vector<int> ranks;

    for (const Card &c : cards)
    {
        ranks.push_back(c.rank);
    }

    sort(ranks.begin(), ranks.end());

    bool straight = true;

    for (int i = 1; i < ranks.size(); i++)
    {
        if (ranks[i] != ranks[i - 1] + 1)
        {
            straight = false;
            break;
        }
    }

    for (auto &r : rankCount)
    {
        if (r.second == 2)
            pairs++;
        if (r.second == 3)
            three = true;
        if (r.second == 4)
            four = true;
    }
    if (straight && flush)
        return "Straight Flush";
    if (flush)
        return "Flush";
    if (straight)
        return "Straight";
    if (four)
        return "Four of a Kind";
    if (three && pairs)
        return "Full House";
    if (three)
        return "Three of a Kind";
    if (pairs == 2)
        return "Two Pair";
    if (pairs == 1)
        return "Pair";

    return "High Card";
}