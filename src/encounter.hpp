#pragma once
#include <string>
#include <vector>
#include "modifier.hpp"
#include "reward.hpp"

struct encounter
{
    std::string name {""};
    int lower {2};
    int upper {12};

    std::vector<modifier> modifiers;
    std::vector<reward> rewards {3};
};