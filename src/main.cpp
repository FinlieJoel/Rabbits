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
