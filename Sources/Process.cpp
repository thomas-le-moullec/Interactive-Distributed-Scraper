#include "Process.hpp"

Plazza::Controller::Process::Process(unsigned int nbThread, ISocket *socket, Plazza::Model::IModel *model, std::vector<Plazza::IStrategyCipher *> &ciphers) : _socket(socket), _fdSocket(socket->socketChild()),
                                                                                                                                                              _ciphers(ciphers), _model(model)
{
  _tp = new ThreadPool(nbThread, model, ciphers);
  std::cout << "Pid du nouveau Process : " << (int)getpid() << std::endl;
}

Plazza::Controller::Process::~Process()
{
}

Plazza::Controller::Order			Plazza::Controller::Process::parseOrder(std::string buff)
{
  orderBySocket orderReceived;
  Order newOrder;

  //buff >> orderReceived;
  if (orderReceived.info == Plazza::Controller::Information::PHONE_NUMBER) {
    newOrder._strategy = new Plazza::ContextInformation(new Plazza::StrategyPhoneNumber());
  }
  if (orderReceived.info == Plazza::Controller::Information::EMAIL_ADDRESS) {
    newOrder._strategy = new Plazza::ContextInformation(new Plazza::StrategyEmailAddress());
  }
  if (orderReceived.info == Plazza::Controller::Information::IP_ADDRESS) {
    newOrder._strategy = new Plazza::ContextInformation(new Plazza::StrategyIpAddress());
  }
  newOrder._file = orderReceived.fileName;
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
      _order = parseOrder(_message);
      _tp->pushOrder(_order);
      _socket->sendMessage(" ", _fdSocket);
    }
  }
}
