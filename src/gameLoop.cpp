#include <iostream>
#include <random>

#include "modifier.hpp"
#include "die.hpp"
#include "hand.hpp"
#include "encounter.hpp"
#include "reward.hpp"

int main()
{
    std::random_device  randomDevice;
    std::mt19937        randomGenerator {randomDevice()};

    encounter e {"Waooga"};
    e.calculateVarianceValue(randomGenerator);

    hand player;
    
    int currentRerolls {player.rerolls};
    
    std::cout << "You face the mighty " << e.name << ". Have your toss land between "<< e.lower << " and " << e.upper << " to move on!\n";
    while (currentRerolls >= 0)
    {
        player.toss(randomGenerator);
        std::cout << "rolled a " << player.sum << "! ";

        if (player.sum >= e.lower && player.sum <= e.upper)
        {
            std::cout << "victory!\n";
            currentRerolls = player.rerolls;
            e.createRewards(randomGenerator);
            e.showRewards();
            break;
        }
        else if (currentRerolls > 0)
        {
            std::cout << "tossing again... (total rerolls left: " << currentRerolls << ")\n";
        }

        --currentRerolls;
    }
    std::cout << "whomp whomp. May the Gods show you the mercy almighty " << e.name << " didn't.\n"; 
}

void coreLoop()
{
    std::random_device  randomDevice;
    std::mt19937        randomGenerator {randomDevice()};

    encounter e {"Waooga"};
    e.calculateVarianceValue(randomGenerator);

    hand player;
    
    int currentRerolls {player.rerolls};
    while (currentRerolls >= 0)
    {
        player.toss(randomGenerator);
        if (player.sum >= e.lower && player.sum <= e.upper)
        {
            currentRerolls = player.rerolls;
            break;
        }

        --currentRerolls;
    }
}