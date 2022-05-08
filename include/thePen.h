#pragma once
#include "../include/bunny.h"
#include <vector>
#include <list>
#include <memory>

class thePen
{
public:
    bool breadingMale;
    int breadingFemale;
    int radioactiveInfection;
    thePen();
    std::list<std::shared_ptr<bunny>> MyBunnyList;
    std::vector<bunny> MyBunnies;
    std::vector<int> furColour;
    void turn();
    void display(int, std::string, std::string, std::string, std::string);
};
