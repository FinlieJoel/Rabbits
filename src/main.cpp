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
        }
    } while (exit == false);

    return 0;
}

// To do,

// efficiencies - ie take colours out that become null, also the static etc key words
// move things to bools that can be moved?
// make sure things are true random , to do this look at teh pokemon code -- ask about this ..
