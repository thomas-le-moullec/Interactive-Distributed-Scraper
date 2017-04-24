#include "ProcessManagerSockets.hpp"

Plazza::Controller::ProcessManagerSockets::ProcessManagerSockets(unsigned int nbThreads) : _numPort(0)
{
  ISocket				*socket;

  socket = new Socket(4000 + _numPort++);
  addProcess(nbThreads, socket);
  _fdProcess.insert(_fdProcess.end(), socket->socketParent());
  _socket = new Socket(5000);
}

Plazza::Controller::ProcessManagerSockets::~ProcessManagerSockets()
{

}

std::vector<std::string> 		Plazza::Controller::ProcessManagerSockets::ParseCommandLine(std::string order)
{
  std::vector<std::string> 	orders;
  std::vector<std::string> 	words;
  std::string								str;
  size_t										pos;

  while ((pos = order.find(" ")) != std::string::npos)
  {
    str = order.substr(0, order.find(" "));
    words.insert(words.end(), str);
    order = order.substr(order.find(" ") + 1, order.length());
  }
  words.insert(words.end(), order);
  for (unsigned int i = 0; i < words.size() - 1; i++)
  {
    str = words[i] + " " + words[words.size() - 1];
    orders.insert(orders.end(), str);
  }
  if (words.size() == 1)
    orders.insert(orders.end(), words[0]);
  return orders;
}

void Plazza::Controller::ProcessManagerSockets::NotifyController(char input)
{
	if (input == '\n')
		control(5);
  else
	 _commandLine += input;
}

int 						Plazza::Controller::ProcessManagerSockets::getStatus()
{
  return 0;
}

int 						Plazza::Controller::ProcessManagerSockets::getPid()
{
  return 0;
}


void						Plazza::Controller::ProcessManagerSockets::addProcess(unsigned int nbThread, ISocket *socket)
{
  pid_t					pid;

  if ((pid = fork()) == 0)
  {
    Process			process(nbThread, socket);

    process.control();
  }
}

void									Plazza::Controller::ProcessManagerSockets::control(unsigned int nbThreads)
{
  std::vector<std::string> commands = ParseCommandLine(_commandLine);

  _processToFeed.first = 0;
  _processToFeed.second = 1000;
  for (unsigned int j = 0; j < commands.size(); j++)
  {
    for (unsigned int i = 0; i < _fdProcess.size(); i++)
    {
      _socket->sendMessage("nbThreadsBusy", _fdProcess[i]);
      _nbThreadsBusy = atoi(_socket->receiveMessage(_fdProcess[i]).c_str());
      if (_nbThreadsBusy == -1)
      {
        _socket->sendMessage("exit", _fdProcess[i]);
        _socket->receiveMessage(_fdProcess[i]);
        close(_fdProcess[i]);
        _fdProcess.erase(_fdProcess.begin() + i);
      }
      else if (_processToFeed.second > _nbThreadsBusy)
      {
        _processToFeed.first = _fdProcess[i];
        _processToFeed.second = _nbThreadsBusy;
      }
    }

    if (_processToFeed.second >= static_cast<int>(nbThreads))
    {
      Socket				*socket;

      socket = new Socket(4000 + _numPort++);
      addProcess(nbThreads, socket);
      _fdProcess.insert(_fdProcess.end(), socket->socketParent());
      _processToFeed.first = _fdProcess[_fdProcess.size() - 1];
      delete socket;
    }

    if (commands[j] == "exit")
    {
      for (unsigned int i = 0; i < _fdProcess.size(); i++)
      {
        _socket->sendMessage("exit", _fdProcess[i]);
        _socket->receiveMessage(_fdProcess[i]);
        close(_fdProcess[i]);
      }
      exit(0);
    }
    else
    {
      _socket->sendMessage(commands[j], _processToFeed.first);
      _socket->receiveMessage(_processToFeed.first);
    }
  }
}
