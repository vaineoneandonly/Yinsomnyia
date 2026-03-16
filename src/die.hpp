#pragma once
#include <vector>
#include <cstdlib>
#include "modifier.hpp"

struct die
{
    int sideCount {6};
    int upperFaceValue {1};

    std::vector<modifier> modifiers;

    void toss() { upperFaceValue = rand() % (sideCount - 1) + 1; }

    void printDebug()
    {
        std::cout << sideCount << " - " << upperFaceValue << '\n';
    }
};