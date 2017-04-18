//
// Created by tchikl_h on 4/14/17.
//

#include <iostream>
#include <string.h>
#include  <stdio.h>
#include  <unistd.h>
#include  <sys/types.h>
#include  <sys/wait.h>
#include <sys/socket.h>
#include "Socket.h"

void    sendMessage(std::string message, int socketFd)
{
    write(socketFd, message.c_str(), strlen(message.c_str()));
}

std::string     receiveMessage(int connFd)
{
    char test[300];
    bzero(test, 301);
    read(connFd, test, 300);

    std::string tester (test);

    if (tester[0] == '\0')
        return ("");
    return (tester);
}

int            addProcess(pid_t *pid, Socket *socket)
{
    int socketFd;
    std::string     buff = "A";

    (*pid) = fork();
    if ((*pid) == 0)
    {
        socketFd = socket->socketChild();
        while (buff != "Y" && buff != "Z")
        {
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

int  main()
{
    std::string buff;
    pid_t     childPid;
    int     status;
    int     socketFd;
    Socket  *socket = new Socket(4555);

    if (addProcess(&childPid, socket) == 1)
        return (0);
    socketFd = socket->socketParent();
    while (buff != "Y" && buff != "Z") {
        buff = "";
        buff = receiveMessage(socketFd);
        std::cout << "Received by parent : " << buff << std::endl;
        if (buff != "") {
            buff[0]++;
            sendMessage(buff, socketFd);
            std::cout << "Send by parent : " << buff << std::endl;
        }
    }
    if (childPid == waitpid(childPid, &status, 0)) {
        close(socketFd);
    }
    return (0);
}