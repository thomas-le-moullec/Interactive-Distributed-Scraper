//
// Created by tchikl_h on 4/14/17.
//

#include        "ProcessManagerSockets.h"

ProcessManagerSockets::ProcessManagerSockets()
{
    Socket              *socket;

    for (int i = 0; i < 10; ++i) {
        socket = new Socket(4000 + i);
        if (addProcess(socket) == 1)
            return (0);
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

    if (tester[0] == '\0')
        return ("");
    return (tester);
}

int             ProcessManagerSockets::addProcess(Socket *socket)
{
    pid_t       pid;
    int         socketFd;
    std::string buff = "A";

    pid = fork();
    if (pid == 0)
    {
        socketFd = socket->socketChild();
        while (buff != "Z" && buff != "[")
        {
            std::cout << "child : " << socket->getPort() << std::endl;
            if (buff != "") {
                buff[0]++;
                sendMessage(buff, socketFd);
                std::cout << "Send by child : " << buff << std::endl;
            }
            buff = "";
            buff = receiveMessage(socketFd);
            std::cout << "Received by child : " << buff << std::endl;
        }
        close(socketFd);
        return (1);
    }
    return (0);
}

void                     ProcessManagerSockets::control()
{
    std::string         buff;

    for (int i = 0; i < 10; ++i) {
        buff = "";
        while (buff != "Z" && buff != "[") {
            std::cout << "parent : " << 4000 + i << std::endl;
            buff = "";
            buff = receiveMessage(this->_fdProcess[i]);
            std::cout << "Received by parent : " << buff << std::endl;
            if (buff != "") {
                buff[0]++;
                sendMessage(buff, this->_fdProcess[i]);
                std::cout << "Send by parent : " << buff << std::endl;
            }
        }
        close(this->_fdProcess[i]);
    }
}