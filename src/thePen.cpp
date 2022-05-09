
#include <iostream>
#include <string>
#include <memory>
#include "../include/thePen.h"
#include <vector>
#include <list>

thePen::thePen()
{
    radioactiveInfection = 0;
    for (int i = 0; i < 5; i++)
    {
        std::shared_ptr<bunny> NewBunny = std::make_shared<bunny>();
        std::cout << "Bunny " << NewBunny->getName() << " was born!\n";
        MyBunnyList.push_back(NewBunny);
    }
};

void thePen::display(int age, std::string name, std::string radioactive, std::string colour, std::string gender)
{
    std::cout << "Rabbit " << name << " is " << radioactive << ", " << age << " years old, " << colour << " in colour and " << gender << std::endl;
}

void thePen::turn()
{
    breadingFemale = 0;
    breadingMale = false;

    for (std::list<std::shared_ptr<bunny>>::iterator f = MyBunnyList.begin(); f != MyBunnyList.end(); ++f)
    {
        (*f)->SetAge();
        thePen::display((*f)->age, (*f)->getName(), (*f)->getRadioactive(), (*f)->getColour(), (*f)->getSex());
        if (radioactiveInfection > 0)
        {
            if ((*f)->radioactive == 0)
            {
                std::cout << "one more radioactive bunny" << std::endl;
                (*f)->turnRadioactive();
                radioactiveInfection--;
                true;
            }
        }
        // This function adds the bunnys to the breading list
        if ((*f)->age > 2 && (*f)->radioactive == 0)
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
        if (((*f)->age == MaxAge && (*f)->radioactive == 0) || ((*f)->age == MaxInfectedAge))
        {
            std::cout << "Bunny " << (*f)->getName() << " has died\n";
            MyBunnyList.erase(f--);
        }
    }
    // This breads the bunnys at the end of the go
    if (breadingMale == true && breadingFemale > 0)
    {
        radioactiveInfection = 0;
        for (int i = 0; i < breadingFemale; i++)
        {
            std::shared_ptr<bunny> NewBunny = std::make_shared<bunny>(furColour.at(i));
            MyBunnyList.push_back(NewBunny);
            std::cout << "Bunny " << NewBunny->getName() << " was born!" << std::endl;
            if (NewBunny->radioactive == 1)
            {
                radioactiveInfection++;
            }
            thePen::display(NewBunny->age, NewBunny->getName(), NewBunny->getRadioactive(), NewBunny->getColour(), NewBunny->getSex());
        }
    }

    std::cout << "AMOUNT OF BUNNIES:  " << MyBunnyList.size() << std::endl;

    if (MyBunnyList.size() > MaxPopulation)
    {

        std::cout << "before the buuny cull size :: " << MyBunnyList.size() << std::endl;
        int remove = MyBunnyList.size() / 2;
        for (int g; g < remove; g++)
        {
            std::list<std::shared_ptr<bunny>>::iterator k = MyBunnyList.begin();
            int randomNumber = rand() % MyBunnyList.size();
            std::advance(k, randomNumber);
            std::cout << "Bunny " << (*k)->getName() << " has died\n";
            MyBunnyList.erase(k);
        }

        std::cout << "After the bunny cull size :: " << MyBunnyList.size() << std::endl;
    }
};
