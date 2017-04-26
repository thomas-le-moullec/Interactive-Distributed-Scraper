#include "Socket.hpp"

Plazza::Controller::Socket::Socket(int port) : _port(port)
{
}

void            Plazza::Controller::Socket::sendMessage(std::string message, int socketFd) const
{
  write(socketFd, message.c_str(), strlen(message.c_str()));
}

std::string    	Plazza::Controller::Socket::receiveMessage(int connFd) const
{
  char        test[300];
  bzero(test, 301);
  read(connFd, test, 300);

  std::string tester (test);
  return (tester);
}

int 										Plazza::Controller::Socket::socketChild()
{
    int 								listenFd;
    struct sockaddr_in 	svrAdd;
    struct hostent 			*server;

    if ((this->_port > 65535) || (this->_port < 2000)) {
        std::cerr << "Please enter port number between 2000 - 65535" << std::endl;
        return 0;
    }

    listenFd = socket(AF_INET, SOCK_STREAM, 0);

    if (listenFd < 0) {
        std::cerr << "Cannot open socket" << std::endl;
        return 0;
    }

    server = gethostbyname("localhost");

    if (server == NULL) {
        std::cerr << "Host does not exist" << std::endl;
        return 0;
    }

    bzero((char *)&svrAdd, sizeof(svrAdd));
    svrAdd.sin_family = AF_INET;

    bcopy((char *) server->h_addr, (char *)&svrAdd.sin_addr.s_addr, server->h_length);

    svrAdd.sin_port = htons(this->_port);

    int checker = connect(listenFd, (struct sockaddr *)&svrAdd, sizeof(svrAdd));

    if (checker < 0) {
        std::cerr << "Cannot connect port " << this->_port << std::endl;
        return 0;
    }
    return (listenFd);
}

int Plazza::Controller::Socket::socketParent()
{
    int 							 listenFd, connFd;
    socklen_t 				 len;
    struct sockaddr_in svrAdd, clntAdd;

    if ((this->_port > 65535) || (this->_port < 2000)) {
        std::cerr << "Please enter a port number between 2000 - 65535" << std::endl;
        return 0;
    }
    listenFd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenFd < 0) {
        std::cerr << "Cannot open socket" << std::endl;
        return 0;
    }
    setsockopt(listenFd, SOL_SOCKET, SO_REUSEADDR, (char *)&len, (int)sizeof(len));
    bzero((char *)&svrAdd, sizeof(svrAdd));

    svrAdd.sin_family = AF_INET;
    svrAdd.sin_addr.s_addr = INADDR_ANY;
    svrAdd.sin_port = htons(this->_port);

    if (bind(listenFd, (struct sockaddr *)&svrAdd, sizeof(svrAdd)) < 0) {
        std::cerr << "Cannot bind" << std::endl;
        return 0;
    }

    listen(listenFd, 5);

    len = sizeof(clntAdd);
    connFd = accept(listenFd, (struct sockaddr *)&clntAdd, &len);
    return (connFd);
}

int Plazza::Controller::Socket::getPort() const
{
    return (this->_port);
}
