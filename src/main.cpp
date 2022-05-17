#include <iostream>
#include "../include/thePen.h"
#include <conio.h>
int main()
{
    thePen MyPen;
    bool exit = false;
    char decision;
    do
    {
        std::cout << "Do you want another turn? (t)urn, e(x)it . .\n";
        decision = getch();
        system("cls");
        switch (decision)
        {
        case 't':
            MyPen.turn();
            exit = MyPen.terminate();
            break;
        case 'T':
            MyPen.turn();
            exit = MyPen.terminate();
            break;
        case 'x':
            exit = true;
            break;
        case 'X':
            exit = true;
            break;

        default:
            std::cout << "Go again .. \n";
            break;
        }
    } while (exit == false);
    return 0;
}
