#pragma once
#include <vector>
#include "die.hpp"

struct hand
{
    std::vector<die> dices {2};
    
    int            sum {0};
    int   totalRerolls {1};
    int currentRerolls {1};

    void add(die newDie) { dices.push_back({newDie}); }
    void upgrade(/*ref to die*/) {}
    void modify(/*ref to die*/) {}
    void remove(/*ref to die */) {}
    
    void increaseRerolls() { ++totalRerolls; }

    void toss(std::mt19937 &generator) 
    {
        sum = 0;
        for (int i = 0; i < dices.size(); ++i) 
        { 
            dices[i].toss(generator);
            sum += dices[i].upperFaceValue; 
        } 
    }

    void printDebug() { for (auto die : dices) { die.printDebug(); } }

};