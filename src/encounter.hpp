#pragma once
#include <string>
#include <vector>
#include "modifier.hpp"
#include "reward.hpp"

struct encounter
{
    std::string name {""};
    int lower {9};
    int upper {11};

    float variancePercentage {0.33};
    int varianceValue {0};

    std::vector<modifier> modifiers;
    std::vector<reward> rewards;

    void calculateVarianceValue(std::mt19937 &generator)
    {
        std::uniform_int_distribution<int> distributor(variancePercentage * lower * -1, variancePercentage * lower);
        varianceValue = distributor(generator);
        std::cout << varianceValue << '\n';

        lower += varianceValue;
        upper += varianceValue;
    }

    void createRewards(std::mt19937 &generator)
    {
        for (int i = 0; i < rewardsAvailable; ++i)
        {
            std::uniform_int_distribution<int> distributor(0, rewardCount - 1);
            rewards.push_back(static_cast<reward>(distributor(generator)));
        }
    }

    void showRewards()
    {
        int i {0};
        for (reward r : rewards)
        {
            std::cout << "reward " << i << " -> ";
            switch (r)
            {
                case  NEWDIEVOUCHER: std::cout << "add a new die to your hand."; break;
                case UPGRADEVOUCHER: std::cout << "upgrade a die in your hand."; break;
                case  MODIFYVOUCHER: std::cout << "modify  a die in your hand."; break;
                case  REMOVEVOUCHER: std::cout << "remove  a die in your hand."; break;
                case   ROLLSVOUCHER: std::cout << "increases     your rerolls.";break;
            }
            ++i;
            std::cout << '\n';
        }
    }
};