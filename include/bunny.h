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
    int age;              // 0-10
    std::string m_colour; // random selection of names.
    std::string m_sex, name, m_radioactive;
    // std::list<int> Rabbit;

    bunny();
    void SetRadioactive();
    // void SetColour();
    void SetColour(int);
    void SetAge();
    void turnRadioactive();
    void SetName();
};