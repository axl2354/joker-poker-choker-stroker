#include <iostream>
#include <algorithm>
#include "RunSession.h"
#include "Deck.h"
#include "Card.h"
#include "hand.h"
#include "ScoringSystem.h"
#include "GameState.h"
using namespace std;
Hand selectCards(Hand &hand)
{
    int amount;

    cout << "How many cards to play? ";
    cin >> amount;

    if (amount <= 0) amount = 1;
    if (amount > hand.size()) amount = hand.size();

    Hand played;
    vector<int> indexes;

    cout << "Enter indexes:\n";

    for (int i = 0; i < amount; i++)
    {
        int index;
        cin >> index;
        indexes.push_back(index);
    }

    for (int index : indexes)
        played.addCard(hand.getCards()[index]);

    sort(indexes.begin(), indexes.end(), greater<int>());

    for (int index : indexes)
        hand.removeCard(index);

    return played;
}
void discardCards(Hand &hand, Deck &deck)
{
    int amount;
    cout << "How many cards to discard? ";
    cin >> amount;

    if (amount <= 0) return;

    if (amount > hand.size())
        amount = hand.size();

    vector<int> indexes;

    cout << "Enter indexes:\n";

    for (int i = 0; i < amount; i++)
    {
        int index;
        cin >> index;
        indexes.push_back(index);
    }

    sort(indexes.begin(), indexes.end(), greater<int>());

    for (int index : indexes)
        hand.removeCard(index);

    while (hand.size() < 8)
        hand.addCard(deck.draw());
}
void drawUpTo(Hand &hand, Deck &deck, int targetSize)
{
    while (hand.size() < targetSize)
    {
        hand.addCard(deck.draw());
    }
}
void runSession()
{
    GameState game;

    game.deck.shuffle();

    game.handsRemaining = 3;
    game.discardsRemaining = 3;
    game.totalScore = 0;
    int totalScore = 0;

    for (int i = 0; i < 8; i++)
        game.hand.addCard(game.deck.draw());

    while (game.handsRemaining > 0)
    {
        cout << "\nYour hand:\n";
        game.hand.print();

        cout << "\nHands: " << game.handsRemaining
             << "  Discards: " << game.discardsRemaining << endl;

        cout << "\nChoose action:\n";
        cout << "1 - Play Hand\n";
        cout << "2 - Discard\n";

        int choice;
        cin >> choice;
        if (choice == 1)
        {
            Hand played = selectCards(game.hand);

            Score score = ScoringSystem::evaluateHand(played);

            int finalScore = score.chips * score.mult;
            totalScore += finalScore;

            cout << "Played: ";
            played.print();

            cout << "Hand: " << score.handName << endl;
            cout << "Score: " << finalScore << endl;

            drawUpTo(game.hand, game.deck, 8);

            game.handsRemaining--;
        }
        else if (choice == 2)
        {
            if (game.discardsRemaining <= 0)
            {
                cout << "No discards left!\n";
                continue;
            }

            discardCards(game.hand, game.deck);
            game.discardsRemaining--;
        }
    }
    cout << "\nFinal Score: " << totalScore << endl;
}
