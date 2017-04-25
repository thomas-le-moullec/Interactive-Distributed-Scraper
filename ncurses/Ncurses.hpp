#ifndef MYNCURSES_H__
# define MYNCURSES_H__

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <bitset>
#include <fstream>
#include <iostream>
#include <string>
#include <ios>
#include <regex>
#include <tuple>
#include <termios.h>
#include <unistd.h>
#include <curses.h>
#include <term.h>
#include <cstring>
#include <sys/ioctl.h>
#include <dirent.h>
#include <dlfcn.h>

class Ncurses
{
private:
    std::string _up;
    std::string _down;
    std::string _left;
    std::string _right;
    std::map<std::string, std::string> _assetPath;

public:
    Ncurses();
    Ncurses(Ncurses const &);
    Ncurses &operator=(Ncurses const &);
    ~Ncurses();
    int         draw();
    int         drawMenu();
    void		createBox(int, int, int, int);
    int	        canonMode(int);
    int         event();

    std::string     getAsset(std::string const &);
    int             countCarriageReturn(std::string const &);
    int             countCharUntilCarriageReturn(std::string const &);
    void            displayAsset(std::string const &, int, int);

};

#endif