//
// Created by tchikl_h on 4/14/17.
//

#include <iostream>
#include <string.h>
#include  <stdio.h>
#include  <unistd.h>
#include  <sys/types.h>

int             socketIn(int);
std::string     receiveMessage(int);
int             socketOut(std::string, int);
void            sendMessage(std::string, int);

void            addProcess()
{
    pid_t   pid;
    std::string     buff = "A";
    int     connFd;
    int     listenFd;

    pid = fork();
    if (pid == 0)
    {
        connFd = socketOut("localhost", 4555);
        listenFd = socketIn(4556);
        while (buff != "Y" && buff != "Z")
        {
            if (buff != "") {
                buff[0]++;
                sendMessage(buff, listenFd);
                std::cout << "Send by son : " << buff << std::endl;
            }
            buff = "";
            buff = receiveMessage(connFd);
            std::cout << "Received by son : " << buff << std::endl;
        }
        close(connFd);
        close(listenFd);
    }
}

int  main()
{
    std::string buff;
    int     connFd;
    int     listenFd;

    addProcess();
    listenFd = socketIn(4555);
    connFd = socketOut("localhost", 4556);
    while (buff != "Y" && buff != "Z")
    {
        buff = "";
        buff = receiveMessage(connFd);
        std::cout << "Received by father : " << buff << std::endl;
        if (buff != "") {
            buff[0]++;
            sendMessage(buff, listenFd);
            std::cout << "Send by father : " << buff << std::endl;
        }
    }
    close(connFd);
    close(listenFd);
    return (0);
}