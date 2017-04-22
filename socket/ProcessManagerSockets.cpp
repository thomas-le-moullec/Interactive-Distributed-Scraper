//
// Created by tchikl_h on 4/14/17.
//

#include        "ProcessManagerSockets.h"

ProcessManagerSockets::ProcessManagerSockets()
{
    Socket              *socket;

    for (int i = 0; i < 10; ++i) {
        socket = new Socket(4000 + i);
        addProcess(socket);
        this->_fdProcess.push_back(socket->socketParent());
        delete (socket);
    }
}

void            ProcessManagerSockets::sendMessage(std::string message, int socketFd)
{
    write(socketFd, message.c_str(), strlen(message.c_str()));
}

std::string     ProcessManagerSockets::receiveMessage(int connFd)
{
    char        test[300];
    bzero(test, 301);
    read(connFd, test, 300);

    std::string tester (test);
    return (tester);
}

int             ProcessManagerSockets::addProcess(Socket *socket)
{
    pid_t       pid;
    int         socketFd;
    int         candy = rand() % 10;
    std::string buff;

    pid = fork();
    if (pid == 0)
    {
        socketFd = socket->socketChild();
        while (1)
        {
            buff = receiveMessage(socketFd);
            std::cout << "CHILD RECEIVED => " << buff << std::endl;
            if (!buff.find("candy ?", 0)) {
                sendMessage(std::to_string(candy), socketFd);
                std::cout << "Child has " << candy << " candies" << std::endl;
            }
            if (!buff.find("give candy", 0)) {
                candy++;
                sendMessage("z", socketFd);
                std::cout << "Child receives candy" << std::endl;
            }
            if (!buff.find("kill yourself", 0) || buff == "") {
                std::cout << "Child commits suicide" << std::endl;
                close(socketFd);
                exit(0);
            }
        }
    }
    return (0);
}

int                     ProcessManagerSockets::takeProcessToFeed()
{
    int                 minCandy = 10;
    int                 nbCandy;
    int                 fdProcessToFeed;
    int                 j = 0;
    std::string         tmp;

    for (int i = 0; i < 10; ++i) {
        this->sendMessage("candy ?", this->_fdProcess[i]);
        tmp = this->receiveMessage(this->_fdProcess[i]);
        std::cout << "PARENT RECEIVED => " << tmp << std::endl;
        if (tmp[tmp.length() - 1] == 'z')
            tmp[tmp.length() - 1] = '\0';
        nbCandy = atoi(tmp.c_str());
        if (nbCandy < minCandy) {
            minCandy = nbCandy;
            fdProcessToFeed = this->_fdProcess[i];
            j = i;
        }
    }
    if (minCandy == 10) {
        for (int i = 0; i < 10; ++i) {
            this->sendMessage("kill yourself", this->_fdProcess[i]);
        }
        return (-1);
    }
    std::cout << "Child " << j << " has only " << minCandy << std::endl;
    return (fdProcessToFeed);
}

void                    ProcessManagerSockets::control()
{
    int                 candy = 100;
    int                 fdProcessToFeed;

    while (1) {
        if ((fdProcessToFeed = this->takeProcessToFeed()) == -1)
            break ;
        sendMessage("give candy", fdProcessToFeed);
        std::cout << "Parent gives him a candy, " << candy << " left" << std::endl;
        candy--;
    }
    for (int i = 0; i < 10; ++i) {
        close(this->_fdProcess[i]);
    }
    std::cout << "PARENT DIE" << std::endl;
}