#include "ProcessManagerSockets.hpp"

Plazza::Controller::ProcessManagerSockets::ProcessManagerSockets(unsigned int nbThreads) : _numPort(0)
{
  ISocket				*socket;

  socket = new Socket(4000 + _numPort++);
  addProcess(nbThreads, socket);
  _fdProcess.insert(_fdProcess.end(), socket->socketParent());
  _socket = new Socket(5000);
  _ciphers[0]  = new Plazza::Xor();
  _ciphers[1] = new Plazza::Caesar();
}

Plazza::Controller::ProcessManagerSockets::~ProcessManagerSockets()
{

}

std::vector<std::string> Plazza::Controller::ProcessManagerSockets::ParseCommandLine(std::string order)
{
  std::vector<std::string> a;

  return a;
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
    Process			process(nbThread, socket, _model, _ciphers);

    process.control();
  }
}

void									Plazza::Controller::ProcessManagerSockets::control(unsigned int nbThreads)
{
  _processToFeed.first = 0;
  _processToFeed.second = 1000;

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

  if (_commandLine == "exit")
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
    _socket->sendMessage(_commandLine, _processToFeed.first);
    _socket->receiveMessage(_processToFeed.first);
  }
}
