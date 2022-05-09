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
        char waitForCharInput(int seconds);
        char c = '1';
        if (kbhit())
        {
            c = getch();
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        //--seconds;

        MyPen.turn();

        /*std::cout << "Do you want another turn? (t)urn, e(x)it . .\n";
        decision = getch();
        switch (decision)
        {
        case 't':
            MyPen.turn();
            break;
        case 'x':
            exit = true;
            break;

        default:
            std::cout << "Go again .. \n";
            break;
        }*/
    } while (exit == false);

    return 0;
}
