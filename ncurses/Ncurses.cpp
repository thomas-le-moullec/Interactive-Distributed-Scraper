#include "Ncurses.hpp"

Ncurses::Ncurses()
{
    newterm(NULL, stderr, stdin);
    keypad(stdscr, TRUE);
    set_escdelay(25);
    noecho();
    curs_set(0);

    this->canonMode(0);

    this->_up = tigetstr("kcuu1");
    this->_down = tigetstr("kcud1");
    this->_left = tigetstr("kcub1");
    this->_right = tigetstr("kcuf1");

    if ((this->_assetPath["plazza"] = getAsset("plazza.txt")) == "")
        this->_assetPath["plazza"] = "THE PLAZZA!";


    start_color();
    init_pair(0, COLOR_BLACK, COLOR_WHITE);
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(4, COLOR_BLUE, COLOR_BLUE);
    init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(6, COLOR_CYAN, COLOR_CYAN);
    init_pair(7, COLOR_WHITE, COLOR_WHITE);
    init_pair(8, COLOR_RED, COLOR_BLACK);
    init_pair(9, COLOR_BLUE, COLOR_BLACK);
    init_pair(10, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(11, COLOR_YELLOW, COLOR_BLACK);
}

Ncurses::Ncurses(Ncurses const &_other)
{
    this->_up = _other._up;
    this->_down = _other._down;
    this->_left = _other._left;
    this->_right = _other._right;
}

Ncurses &Ncurses::operator=(Ncurses const &_other)
{
    if (this != &_other)
    {
        this->_up = _other._up;
        this->_down = _other._down;
        this->_left = _other._left;
        this->_right = _other._right;
    }
    return (*this);
}

Ncurses::~Ncurses()
{
    this->canonMode(1);
    endwin();
}

std::string     Ncurses::getAsset(std::string const &file_name)
{
    std::ifstream file(file_name);
    std::string str;
    std::stringstream   ss;

    if (file_name.empty() || !std::ifstream(file_name))
        return ("");
    while (std::getline(file, str))
    {
        ss << str << '\n';
    }
    return (ss.str());
}

int         Ncurses::countCarriageReturn(std::string const &asset)
{
    int     carriageReturn = 0;

    for (int i = 0 ; asset[i] != '\0' ; i++)
    {
        if (asset[i] == '\n')
            carriageReturn++;
    }
    return (carriageReturn);
}

int         Ncurses::countCharUntilCarriageReturn(std::string const &asset)
{
    int     max = 0;

    for (int i = 0 ; asset[i] != '\0' && asset[i] != '\n'; i++)
    {
        max++;
    }
    return (max);
}

void        Ncurses::displayAsset(std::string const &str, int posx, int posy)
{
    int     i = 0;
    int     y = 0;
    int     x = 0;
    char    *asset = strdup(str.c_str());
    char    c;

    if (str.length() > 1)
        asset[str.length() - 1] = '\0';
    while (asset[i] != '\0')
    {
        if (asset[i] == '\n') {
            x = 0;
            y++;
            i++;
        }
        c = asset[i];
        if (c != '\0' && c != '\n' && c != '\\')
        {
            attron(A_BOLD);
            mvaddch(posy - this->countCarriageReturn(asset) / 2 + y,
                    posx - this->countCharUntilCarriageReturn(asset) / 2 + x, c);
            attroff(A_BOLD);
        }
        i++;
        x++;
    }
}

int	Ncurses::canonMode(int mode)
{
    static struct termios prev;
    static struct termios next;

    if (mode == 0)
    {
        if (ioctl(0, TCGETS, &prev) < 0)
            return (-1);
        if (ioctl(0, TCGETS, &next) < 0)
            return (-1);
        next.c_lflag &= ~ECHO;
        next.c_lflag &= ~ICANON;
        next.c_cc[VMIN] = 0;
        next.c_cc[VTIME] = 0;
        if (ioctl(0, TCSETS, &next) < 0)
            return (-1);
    }
    else
    if (ioctl(0, TCSETS, &prev) < 0)
        return (-1);
    return (0);
}

int                 Ncurses::draw()
{
    clear();
    if (this->event() == -1)
        return (-1);
    refresh();
    return (0);
}

int                 Ncurses::drawMenu()
{
    clear();
    if (this->event() == -2)
        return (-1);
    this->displayAsset(this->_assetPath["plazza"], COLS / 2, LINES / 2);
    refresh();
    return (0);
}

void		Ncurses::createBox(int height, int width, int posX, int posY)
{
    WINDOW *win = newwin(height, width, posX, posY);
    box(win, 0, 0);
    wrefresh(win);
}

int                Ncurses::event()
{
    char buff[25];
    int  nb;

    nb = read(0, buff, 25);
    buff[nb] = '\0';
    std::string key(buff);

    if (key.compare(0, 3, this->_left) == 0)
        mvprintw(0, 0, "[LEFT]");
    else if (key.compare(0, 3, this->_right) == 0)
        mvprintw(0, 0, "[RIGHT]");
    else if (key.compare(0, 3, this->_up) == 0)
        mvprintw(0, 0, "[UP]");
    else if (key.compare(0, 3, this->_down) == 0)
        mvprintw(0, 0, "[DOWN]");
    else if (key[0] == '\n')
        mvprintw(0, 0, "[ENTER]");
    else if (key[0] == 27) {
        mvprintw(0, 0, "[ESCAPE]");
        return (-1);
    }
    else if (key[0] == ' ') {
        mvprintw(0, 0, "[SPACE]");
        return (-2);
    }
    else
        mvprintw(0, 0, "[NONE]");
    return (0);
}