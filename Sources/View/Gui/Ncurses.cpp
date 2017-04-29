#include "Ncurses.hpp"

int Plazza::View::Ncurses::modeCanonique(int mode) {
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

void 								Plazza::View::Ncurses::Update(std::vector<std::string> data) {
  std::vector<int> 	infosProcess;
  WINDOW 						*winMenu = newwin(10, COLS - 4, 1, 2);
  WINDOW 						*winDatas = newwin(30, COLS - 4, 12, 2);
  int								x = 0;
  int								y = 0;

  //initscr();
  wclear(winMenu);
  wclear(winDatas);

  box(winMenu, 0, 0);
  box(winDatas, 0, 0);

  mvwprintw(winMenu, 1, 1, "ENTRER YOUR COMMAND LINE %s", _commandToPrint.c_str());
  infosProcess = static_cast<Plazza::Controller::ProcessManagerSockets *>(_processManager)->getStatus();
  mvwprintw(winMenu, 3, 1, "Nombre de processus actifs : %d", infosProcess[0]);
  for (unsigned int i = 2; i < infosProcess.size(); i++)
    mvwprintw(winMenu, 2 + i, 1, "   Processus N. %u : %d/%d threads occupés, ", i - 2, infosProcess[i], infosProcess[1]);
  wrefresh(winMenu);

  wrefresh(winDatas);
  for (unsigned int i = 0; i < data.size(); i++)
  {
    mvwprintw(winDatas, 1 + y, 1 + x, "%s", data[i].c_str());
    wrefresh(winDatas);
    usleep(100000);
    y++;
    if (i % 25 == 0 && i != 0) {
      x += 27;
      y = 0;
    }
    if (x > 27 * 3){
      x = 0;
      wclear(winDatas);
      box(winDatas, 0, 0);
    }
  }
}

void Plazza::View::Ncurses::initView() {
}

void 												Plazza::View::Ncurses::getInputs() {
  char											buff[1];
  std::vector<std::string> 	data;

  Update(data);
  buff[0] = ' ';

  while (buff[0] != 10 && buff[0] != 13) {
    read(1, &buff, 1);
    if (buff[0] != 10 && buff[0] != 13) {
      _commandToPrint += buff[0];
      Update(data);
    }
    if (buff[0] == 127) {
      _commandToPrint = _commandToPrint.substr(0, _commandToPrint.length() - 2);
      Update(data);
    }
  }
  if (_commandToPrint == "exit")
    endwin();
  _processManager->NotifyController(_commandToPrint);
  _commandToPrint = "";
}

void Plazza::View::Ncurses::displayData() {
}

void Plazza::View::Ncurses::displayStatus() {
}

Plazza::View::Ncurses::Ncurses(Plazza::Controller::IController *controller) : AView(controller), _commandToPrint("") {
  newterm(NULL, stderr, stdin);
  keypad(stdscr, TRUE);
  set_escdelay(25);
  noecho();
  curs_set(0);
  _commandToPrint = "";
  //modeCanonique(0);
}

Plazza::View::Ncurses::~Ncurses() {
  endwin();
  //modeCanonique(1);
}

void Plazza::View::Ncurses::LoopView() {
    while (true) {
        getInputs();
    }
}
