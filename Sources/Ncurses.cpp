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
  clear();
  mvprintw(1, 1, "ENTRER YOUR COMMAND LINE %s", _commandToPrint.c_str());
  infosProcess = static_cast<Plazza::Controller::ProcessManagerSockets *>(_processManager)->getStatus();
  for (unsigned int i = 0; i < infosProcess.size(); i++)
    mvprintw(10 + i, 1, "%d", infosProcess[i]);

  for (unsigned int i = 0; i < data.size(); i++)
    mvprintw(5 + i, 1, "%s", data[i].c_str());
  refresh();
}

void Plazza::View::Ncurses::initView() {
}

void Plazza::View::Ncurses::getInputs() {
  char	buff[1];
  std::vector<std::string> data;

  Update(data);
  read(1, &buff, 1);
  _commandToPrint += buff[0];
  //std::cout << (int)buff[0] << std::endl;
  if (buff[0] == 127)
    _commandToPrint = _commandToPrint.substr(0, _commandToPrint.length() - 2);
  if (buff[0] == 10 || buff[0] == 13)
    _commandToPrint = "";
  Update(data);
  _processManager->NotifyController(buff[0]);
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
  //modeCanonique(0);
}

Plazza::View::Ncurses::~Ncurses() {
  //modeCanonique(1);
}

void Plazza::View::Ncurses::LoopView() {
    while (true) {
        getInputs();
    }
}
