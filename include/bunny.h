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

    enum e_radioactive
    {
        normal,
        radioactive
    };
    enum e_radioactive i_radioactive;

    // bool radioactive;

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
    // void SetRadioactive();
    void SetColour(int);
    void SetAge();
    void turnRadioactive();
    std::string getRadioactive();
    std::string getColour();
    std::string getSex();
    std::string getName();
    int V_names();
};