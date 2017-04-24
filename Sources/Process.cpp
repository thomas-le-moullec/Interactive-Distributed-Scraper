#include "Process.hpp"

Plazza::Controller::Process::Process(unsigned int nbThread, ISocket *socket) : _socket(socket), _fdSocket(socket->socketChild())
{
  _tp = new ThreadPool(nbThread);
  std::cout << "Pid du nouveau Process : " << (int)getpid() << std::endl;
}

Plazza::Controller::Process::~Process()
{
}

Plazza::Controller::Order			Plazza::Controller::Process::parseOrder(std::string buff)
{
  
  buff << _order;
}

void				Plazza::Controller::Process::control()
{
  while (true)
  {
    _message = _socket->receiveMessage(_fdSocket);
    if (_message == "nbThreadsBusy")
      _socket->sendMessage(std::to_string(_tp->getCurrentOrder()), _fdSocket);
    else if (_message == "exit")
    {
      _socket->sendMessage(" ", _fdSocket);
      close(_fdSocket);
      exit(0);
    }
    else
    {
      parseOrder(_message);
      //_order._file = _message;
      _tp->pushOrder(_order);
      _socket->sendMessage(" ", _fdSocket);
    }
  }
}
