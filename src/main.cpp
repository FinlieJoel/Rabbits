#include <iostream>
#include "../include/thePen.h"
#include <conio.h>
#include <chrono>
#include <thread>
#include <time.h>

int main()
{

    thePen MyPen;
    bool exit = false;
    char decision;
    do
    {

        char i = 'f';
        if (kbhit())
        {
            i = getch();
            if (i == 'k' || 'K')
            {
                MyPen.cull();
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        MyPen.turn();
        exit = MyPen.terminate();

    } while (exit == false);

    return 0;
}
