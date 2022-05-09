#pragma once
#include <string>

class bunny
{
    int i_firstName, i_lastName;
    int V_names();

public:
    enum e_sex
    {
        female,
        male
    };
    enum e_sex i_sex;
    bool infected;
    enum e_colour
    {
        white,
        brown,
        black,
        spotted
    };
    enum e_colour i_colour;
    int age;

    bunny();
    bunny(int);
    void SetAge();
    void turnInfected();
    std::string getInfected();
    std::string getColour();
    std::string getSex();
    std::string getName();
};