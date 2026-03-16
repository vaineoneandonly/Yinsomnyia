#pragma once
#include <vector>
#include "die.hpp"

struct hand
{
    std::vector<die> dices {2};
    
    int sum     {0};
    int rerolls {1};

    void add(die newDie) { dices.push_back({newDie}); }
    void upgrade(/*ref to die*/) {}
    void modify(/*ref to die*/) {}
    void remove(/*ref to die */) {}
    
    void increaseRerolls() {}

    void toss(/*ref to dices*/) 
    {
        sum = 0;
        for (int i = 0; i < dices.size(); ++i) 
        { 
            dices[i].toss();
            sum += dices[i].upperFaceValue; 
        } 
    }

    void printDebug() { for (auto die : dices) { die.printDebug(); } }

};