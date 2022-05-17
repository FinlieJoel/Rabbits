
#include <iostream>
#include <string>
#include "../include/thePen.h"
#include <thread>

thePen::thePen()
{
    noInfected = 0;
    for (int i = 0; i < 5; i++)
    {
        std::shared_ptr<bunny> NewBunny = std::make_shared<bunny>();
        std::cout << "Bunny " << NewBunny->getName() << " was born!\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        MyBunnyList.push_back(NewBunny);
        if (NewBunny->infected == 1)
        {
            noInfected++;
        }
        thePen::display(NewBunny->age, NewBunny->getName(), NewBunny->getInfected(), NewBunny->getColour(), NewBunny->getSex());
    }
};

void thePen::display(int &age, std::string name, std::string infected, std::string colour, std::string gender)
{
    std::cout << "Rabbit " << name << " is " << infected << ", " << age << " years old, " << colour << " in colour and " << gender << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void thePen::turn()
{
    breadingFemale = 0;
    breadingMale = false;
    int noInfectedCopy = noInfected;

    for (std::list<std::shared_ptr<bunny>>::iterator f = MyBunnyList.begin(); f != MyBunnyList.end(); ++f)
    {
        (*f)->SetAge();
        if (noInfectedCopy > 0) // Infecting from the newborns
        {
            if ((*f)->infected == 0)
            {
                (*f)->turnInfected();
                noInfectedCopy--;
                noInfected++; // comment this out to reduce infections and the simulation will last longer.
            }
        }
        if ((*f)->age >= breadingAge && (*f)->infected == 0) // Setting the amount of breeding females and male
        {
            if ((*f)->i_sex == 1)
            {
                breadingFemale++;
                furColour.push_back((*f)->i_colour);
            }
            if ((*f)->i_sex == 0)
            {
                breadingMale = true;
            }
        }

        if (((*f)->age == MaxAge && (*f)->infected == 0) || ((*f)->age == MaxInfectedAge)) // Death of bunny or display
        {
            std::cout << "Bunny " << (*f)->getName() << " has died\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            if ((*f)->infected == true)
            {
                noInfected--;
            }
            MyBunnyList.erase(f--);
        }
        else
        {
            thePen::display((*f)->age, (*f)->getName(), (*f)->getInfected(), (*f)->getColour(), (*f)->getSex());
        }
    }

    thePen::breed();
    std::cout << "AMOUNT OF BUNNIES:  " << MyBunnyList.size() << " NUMBER BORN INFECTED: " << noInfected << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    thePen::cull();
};

void thePen::cull()
{
    if (MyBunnyList.size() > MaxPopulation)
    {
        std::cout << "before the buuny cull size :: " << MyBunnyList.size() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        int removeNum = MyBunnyList.size() / 2;
        for (int g = 0; g < removeNum; g++)
        {
            std::list<std::shared_ptr<bunny>>::iterator k = MyBunnyList.begin();
            int randomNumber = rand() % MyBunnyList.size();
            std::advance(k, randomNumber);
            std::cout << "Bunny " << (*k)->getName() << " has died\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            if ((*k)->infected == true)
            {
                noInfected--;
            }
            MyBunnyList.erase(k);
        }
        std::cout << "After the bunny cull, population size is: " << MyBunnyList.size() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void thePen::breed()
{
    if (breadingMale == true && breadingFemale > 0)
    {
        // noInfected = 0;
        for (int i = 0; i < breadingFemale; i++)
        {
            std::shared_ptr<bunny> NewBunny = std::make_shared<bunny>(furColour.at(i));
            MyBunnyList.push_back(NewBunny);
            std::cout << "Bunny " << NewBunny->getName() << " was born!" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            if (NewBunny->infected == 1)
            {
                noInfected++;
            }
            thePen::display(NewBunny->age, NewBunny->getName(), NewBunny->getInfected(), NewBunny->getColour(), NewBunny->getSex());
        }
    }
}
bool thePen::terminate()
{
    if (MyBunnyList.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}