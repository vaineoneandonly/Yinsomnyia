#include <iostream>

#include "modifier.hpp"
#include "die.hpp"
#include "hand.hpp"
#include "encounter.hpp"

int main()
{

    encounter e {"Waooga"};
    e.lower = 10;
    e.upper = 14;
    hand player;

    int currentRerolls {player.rerolls};
    std::cout << "You face the mighty " << e.name << ". Have your toss land between "<< e.lower << " and " << e.upper << " to move on!\n";
    while (currentRerolls >= 0)
    {
        player.toss();
        std::cout << "rolled a " << player.sum << "! ";

        if (player.sum >= e.lower && player.sum <= e.upper)
        {
            std::cout << "victory!\n";
            currentRerolls = player.rerolls;
            break;
        }
        else
        {
            std::cout << "tossing again... (total rerolls left: " << currentRerolls << ")\n";
            --currentRerolls;
        }
    }

    std::cout << "rolled a " << player.sum << "! ";
    std::cout << "may the Gods show you the mercy almighty " << e.name << " didn't.\n"; 
}