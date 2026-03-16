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
    
    int rewardSelection {-1};

    while (player.currentRerolls >= 0)
    {
        std::cout << "You face the mighty " << e.name << ". Have your toss land between "<< e.lower << " and " << e.upper << " to move on!\n";
        player.toss(randomGenerator);
        std::cout << "rolled a " << player.sum << "! ";

        if (player.sum >= e.lower && player.sum <= e.upper)
        {
            std::cout << "victory!\n";
            player.currentRerolls = player.totalRerolls;
            e.createRewards(randomGenerator);
            e.showRewards();
            
            std::cout << "choose one of the above rewards: ";
            std::cin >> rewardSelection;

            switch(e.rewards[rewardSelection])
            {
                case  NEWDIEVOUCHER: player.add({}); break;
                case UPGRADEVOUCHER: std::cout << "upgrade a die in your hand."; break;
                case  MODIFYVOUCHER: std::cout << "modify  a die in your hand."; break;
                case  REMOVEVOUCHER: std::cout << "remove  a die in your hand."; break;
                case   ROLLSVOUCHER: player.increaseRerolls(); break;
            }

            e.rewards.clear();
        }
        else if (player.currentRerolls > 0)
        {
            std::cout << "tossing again... (total rerolls left: " << player.currentRerolls << ")\n";
        }

        --player.currentRerolls;
    }
    std::cout << "whomp whomp. May the Gods show you the mercy almighty " << e.name << " didn't.\n"; 
}
