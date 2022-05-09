#pragma once
#include "../include/bunny.h"
#include <vector>
#include <list>
#include <memory>

class thePen
{
    const int MaxAge = 9;
    const int MaxInfectedAge = 49;
    const int MaxPopulation = 999;
    const int breadingAge = 2;
    bool breadingMale;
    int breadingFemale;
    int radioactiveInfection;

    void display(int, std::string, std::string, std::string, std::string);
    std::list<std::shared_ptr<bunny>> MyBunnyList;
    std::vector<int> furColour;

public:
    thePen();
    void turn();
    void death();
};
