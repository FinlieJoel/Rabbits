#include <iostream>
#include "../include/thePen.h"
#include <conio.h>
#include <chrono>
#include <thread>

int main()
{

    thePen MyPen;
    bool exit = false;
    char decision;
    do
    {
        MyPen.turn();

        std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    } while (exit == false);

    return 0;
}
