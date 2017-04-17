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

int             socketIn(int);
std::string     receiveMessage(int);
int             socketOut(std::string, int);
void            sendMessage(std::string, int);

int            addProcess(pid_t *pid)
{
    std::string     buff = "A";
    int     socketFd;

    (*pid) = fork();
    if ((*pid) == 0)
    {
        socketFd = socketOut("localhost", 4555);
        while (buff != "Y" && buff != "Z")
        {
            if (buff != "") {
                buff[0]++;
                sendMessage(buff, socketFd);
                std::cout << "Send by child : " << buff << std::endl;
            }
            buff = "";
            buff = receiveMessage(socketFd); // listen
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

    if (addProcess(&childPid) == 1)
        return (0);
    socketFd = socketIn(4555);
    while (buff != "Y" && buff != "Z") {
        buff = "";
        buff = receiveMessage(socketFd); // listen
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