//
// Created by tchikl_h on 4/25/17.
//

#include "Ncurses.hpp"

int         main()
{
    int     res = 0;
    Ncurses *ncurses = new Ncurses;

    while (res != -1) {
        res = ncurses->drawMenu();
        usleep(80000);
    }
    res = 0;
    while (res != -1) {
        res = ncurses->draw();
        usleep(80000);
    }
    delete ncurses;
    return  (0);
}