#pragma once
#include "../include/bunny.h"
#include <vector>
#include <list>
#include <memory>

class thePen
{
    const int MaxAge = 10;
    const int MaxInfectedAge = 50;
    const int breadingAge = 2;
    bool breadingMale;
    int breadingFemale;
    int noInfected;
    void display(int, std::string, std::string, std::string, std::string);
    std::list<std::shared_ptr<bunny>> MyBunnyList;
    std::vector<int> furColour;
    void breed();

public:
    thePen();
    void turn();
    bool terminate();
    void cull();
};
