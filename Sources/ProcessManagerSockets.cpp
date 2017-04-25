#include "ProcessManagerSockets.hpp"

Plazza::Controller::ProcessManagerSockets::ProcessManagerSockets(unsigned int nbThreads, Plazza::Model::IModel *model) : AController(model), _numPort(0)
{
  ISocket				*socket;

  socket = new Socket(4000 + _numPort++);
    _ciphers.insert(_ciphers.end(), new Plazza::Xor());
    _ciphers.insert(_ciphers.end(), new Plazza::Caesar());
  addProcess(nbThreads, socket);
  _fdProcess.insert(_fdProcess.end(), socket->socketParent());
  _socket = new Socket(5000);
    std::cout << "size _ciphers => " << _ciphers.size() << std::endl; //AFFICHE
  _strEnum["PHONE_NUMBER"] = Plazza::Controller::PHONE_NUMBER;
  _strEnum["EMAIL_ADDRESS"] = Plazza::Controller::EMAIL_ADDRESS;
  _strEnum["IP_ADDRESS"] = Plazza::Controller::IP_ADDRESS;
}

Plazza::Controller::ProcessManagerSockets::~ProcessManagerSockets()
{
}

std::vector<std::string> 		Plazza::Controller::ProcessManagerSockets::ParseCommandLine(std::string order) // Not Correct
{
  std::vector<std::string>	ordersSeparator;
  std::vector<std::string> 	orders;
  std::vector<std::string> 	words;
  std::string								strToPush;
  size_t										pos;

  //std::cout << "Command Line -> " << order << std::endl;
  while ((pos = order.find(";")) != std::string::npos)
  {
    strToPush = order.substr(0, pos);
    ordersSeparator.insert(ordersSeparator.end(), strToPush);
    order = order.substr(pos + 1, order.length());
  }
  ordersSeparator.insert(ordersSeparator.end(), order);
  //for (unsigned int i = 0; i < ordersSeparator.size(); i++)
    //std::cout << "ordersSeparator[" << i << "] : ." << ordersSeparator[i] << "." << std::endl;
  for (unsigned int j = 0; j < ordersSeparator.size(); j++)
  {
    words.clear();
    while ((pos = ordersSeparator[j].find(" ")) != std::string::npos)
    {
      strToPush = ordersSeparator[j].substr(0, pos);
      if (strToPush != "")
        words.insert(words.end(), strToPush);
      ordersSeparator[j] = ordersSeparator[j].substr(pos + 1, ordersSeparator[j].length());
    }
    if (ordersSeparator[j] != "")
      words.insert(words.end(), ordersSeparator[j]);
    //for (unsigned int i = 0; i < words.size(); i++)
      //std::cout << "words[" << i << "] : ." << words[i] << "." << std::endl;
    for (unsigned int i = 0; i < words.size() - 1; i++)
    {
      strToPush = words[i] + " " + words[words.size() - 1];
      orders.insert(orders.end(), strToPush);
    }
    if (words.size() == 1)
      orders.insert(orders.end(), words[0]);
  }
  for (unsigned int i = 0; i < orders.size(); i++)
    std::cout << "Orders[" << i << "] : " << orders[i] << std::endl;
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
    Process			process(nbThread, socket, _model, _ciphers);

    process.control();
  }
}

Plazza::Controller::orderBySocket 	Plazza::Controller::ProcessManagerSockets::fromBufferToStruct(std::string str)
{
  Plazza::Controller::orderBySocket	order;
  std::string												enums;
  size_t														pos;

  if ((pos = str.find(" ")) != std::string::npos)
  {
    order.fileName = str.substr(0, str.find(" "));
    enums = str.substr(str.find(" ") + 1, str.length());
    if (enums == "PHONE_NUMBER" || enums == "EMAIL_ADDRESS" || enums == "IP_ADDRESS")
      order.info = _strEnum[enums];
    else
      order.info = _strEnum["PHONE_NUMBER"]; // THROW UNE ERREUR
  }
  else
  {
    //THROW UNE ERREUR
    order.fileName = "";
    order.info = _strEnum["PHONE_NUMBER"];
  }
  return order;
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
      Plazza::Controller::orderBySocket order	= fromBufferToStruct(commands[j]);
      commands[j] = "";
      commands[j] << order;
      std::cout << "Order info => " << (int)order.info << "Order fileName => " << order.fileName << std::endl;
      //std::cout << commands[j] << std::endl;
      _socket->sendMessage(commands[j], _processToFeed.first);
      _socket->receiveMessage(_processToFeed.first);
    }
  }
  _commandLine = "";
}
