#pragma once
#include <vector>
#include <random>
#include "modifier.hpp"
struct die
{
    int sideCount       {6};
    int upperFaceValue  {1};

    std::vector<modifier> modifiers;

    void toss(std::mt19937 &generator) 
    {
        std::uniform_int_distribution<> distributor(1, sideCount);
        int newUpperFaceValue {distributor(generator)};

        upperFaceValue = newUpperFaceValue; 
    }

    void printDebug()
    {
        for (auto modifier : modifiers)
        {
            std::cout << upperFaceValue;
        }
        std::cout << '-';
    }
};