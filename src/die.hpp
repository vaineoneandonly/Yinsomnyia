#pragma once
#include <vector>
#include <random>
#include "modifier.hpp"
struct die
{
    int sideCount       {6};
    int upperFaceValue  {1};

    std::vector<modifier> modifiers;

    void toss() 
    {
        std::random_device  rd;
        std::mt19937        g {rd()};

        std::uniform_int_distribution<> d(1, sideCount);
        int newUpperFaceValue {d(g)};

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