#include <iostream>
#include "ShopSystem.h"
#include "ModifierFactory.h"

using namespace std;

void ShopSystem::openShop(GameState &game)
{
    cout << "\n=== SHOP ===\n";
    cout << "Money: $" << game.money << endl;

    cout << "1 - Buy Random Toker ($5)\n";
    cout << "2 - Leave Shop\n";

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        if (game.money < 5)
        {
            cout << "Not enough money!\n";
            return;
        }

        game.money -= 5;

        IModifier* newToker = ModifierFactory::createRandom();

        game.tokers.push_back(newToker);

        cout << "You bought a Toker!\n";
    }
}