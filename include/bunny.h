#pragma once
#include <string>
#include <list>

class bunny
{
public:
    enum e_sex
    {
        female,
        male
    };
    enum e_sex i_sex;

    bool radioactive;

    enum e_colour
    {
        white,
        brown,
        black,
        spotted
    };
    enum e_colour i_colour;
    int age;
    int i_firstName, i_lastName;

    bunny();
    bunny(int);
    void SetAge();
    void turnRadioactive();
    std::string getRadioactive();
    std::string getColour();
    std::string getSex();
    std::string getName();
    int V_names();
};