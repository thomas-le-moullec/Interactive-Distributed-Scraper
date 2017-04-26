#include "ProcessManagerSockets.hpp"

Plazza::Controller::ProcessManagerSockets::ProcessManagerSockets(unsigned int nbThreads, Plazza::Model::IModel *model) : AController(model), _numPort(0)
{
  ISocket				*socket;

  socket = new Socket(4000 + _numPort++);
  addProcess(nbThreads, socket);
  _fdProcess.insert(_fdProcess.end(), socket->socketParent());
  //_socket = new Socket(5000);
  _strEnum["PHONE_NUMBER"] = Plazza::Controller::PHONE_NUMBER;
  _strEnum["EMAIL_ADDRESS"] = Plazza::Controller::EMAIL_ADDRESS;
  _strEnum["IP_ADDRESS"] = Plazza::Controller::IP_ADDRESS;
}

Plazza::Controller::ProcessManagerSockets::~ProcessManagerSockets()
{
}

void            Plazza::Controller::ProcessManagerSockets::sendMessage(std::string message, int socketFd) const
{
    write(socketFd, message.c_str(), strlen(message.c_str()));
}

std::string    	Plazza::Controller::ProcessManagerSockets::receiveMessage(int connFd) const
{
    char        test[300];
    bzero(test, 301);
    read(connFd, test, 300);

    std::string tester (test);
    return (tester);
}

std::vector<std::string> 		Plazza::Controller::ProcessManagerSockets::ParseCommandLine(std::string order)
{
  std::vector<std::string>	ordersSeparator;
  std::vector<std::string> 	orders;
  std::vector<std::string> 	words;
  std::string								strToPush;
  size_t										pos;

  //std::cout << "Command Line -> " << order << std::endl;
    ordersSeparator.clear();
    orders.clear();
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
	if (input == 10 || input == 13)
		control(5);
  else
	 _commandLine += input;
}

std::vector<int> 						Plazza::Controller::ProcessManagerSockets::getStatus()
{
  std::vector<int> 					infosProcess;

  infosProcess.insert(infosProcess.end(), _fdProcess.size());
  for (unsigned int i = 0; i < _fdProcess.size(); i++)
  {
    sendMessage("nbThreadsBusy", _fdProcess[i]);
    _nbThreadsBusy = atoi(receiveMessage(_fdProcess[i]).c_str());
    if (_nbThreadsBusy != -1)
      infosProcess.insert(infosProcess.end(), _nbThreadsBusy);
  }
  return infosProcess;
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
    Process			process(nbThread, socket, _model);

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
      throw RunTimeErrorController("Format is : [FILENAME] [DATA PATTERN]. Example : toto.html PHONE_NUMBER");
  }
  else
    throw RunTimeErrorController("Format is : [FILENAME] [DATA PATTERN]. Example : toto.html PHONE_NUMBER");
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
      sendMessage("nbThreadsBusy", _fdProcess[i]);
      _nbThreadsBusy = atoi(receiveMessage(_fdProcess[i]).c_str());
      if (_nbThreadsBusy == -1)
      {
        sendMessage("exit", _fdProcess[i]);
        receiveMessage(_fdProcess[i]);
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
        sendMessage("exit", _fdProcess[i]);
        receiveMessage(_fdProcess[i]);
        close(_fdProcess[i]);
      }
      exit(0);
    }
    else
    {
        Plazza::Controller::orderBySocket order;
      try {
          order	= fromBufferToStruct(commands[j]);
      }
      catch (RunTimeErrorController const &stdErr) {
        std::cerr << stdErr.what() << std::endl;
        _commandLine = "";
        return;
      }
      commands[j] = "";
      commands[j] << order;
      std::cout << "Order info => " << (int)order.info << "Order fileName => " << order.fileName << std::endl;
      //std::cout << commands[j] << std::endl;
      sendMessage(commands[j], _processToFeed.first);
      receiveMessage(_processToFeed.first);
    }
  }
    _commandLine = "";
}
