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
    std::vector<reward> rewards {3};

    void calculateVarianceValue(std::mt19937 &generator)
    {
        std::uniform_int_distribution<int> distributor(variancePercentage * lower * -1, variancePercentage * lower);
        varianceValue = distributor(generator);
        std::cout << varianceValue << '\n';

        lower += varianceValue;
        upper += varianceValue;
    }
};