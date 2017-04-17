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
    int     connFd;
    int     listenFd;

    (*pid) = fork();
    if ((*pid) == 0)
    {
        listenFd = socketOut("localhost", 4555);
        write(listenFd, ".", 1);
        connFd = socketIn(4556);
        while (buff != "Y" && buff != "Z")
        {
            if (buff != "") {
                buff[0]++;
                sendMessage(buff, connFd);
                std::cout << "Send by child : " << buff << std::endl;
            }
            buff = "";
            buff = receiveMessage(listenFd);
            std::cout << "Received by child : " << buff << std::endl;
        }
        close(connFd);
        close(listenFd);
        return (1);
    }
    return (0);
}

int  main()
{
    std::string buff;
    pid_t     childPid;
    int     status;
    int     connFd;
    int     listenFd;

    if (addProcess(&childPid) == 1)
        return (0);
    connFd = socketIn(4555);
    listenFd = socketOut("localhost", 4556);
    write(listenFd, ".", 1);
    while (buff != "Y" && buff != "Z") {
        buff = "";
        buff = receiveMessage(listenFd);
        std::cout << "Received by parent : " << buff << std::endl;
        if (buff != "") {
            buff[0]++;
            sendMessage(buff, connFd);
            std::cout << "Send by parent : " << buff << std::endl;
        }
    }
    if (childPid == waitpid(childPid, &status, 0)) {
        close(connFd);
        close(listenFd);
    }
    return (0);
}