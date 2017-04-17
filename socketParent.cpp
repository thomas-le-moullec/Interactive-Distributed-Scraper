//
// Created by tchikl_h on 4/13/17.
//

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <fstream>
#include <strings.h>
#include <stdlib.h>
#include <string>
#include <pthread.h>

int socketParent(int port) {
    int portNo;
    int listenFd, connFd;
    socklen_t len;
    struct sockaddr_in svrAdd, clntAdd;

    portNo = port;

    if ((portNo > 65535) || (portNo < 2000)) {
        std::cerr << "Please enter a port number between 2000 - 65535" << std::endl;
        return 0;
    }
    listenFd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenFd < 0) {
        std::cerr << "Cannot open socket" << std::endl;
        return 0;
    }

    bzero((char *)&svrAdd, sizeof(svrAdd));

    svrAdd.sin_family = AF_INET;
    svrAdd.sin_addr.s_addr = INADDR_ANY;
    svrAdd.sin_port = htons(portNo);

    if (bind(listenFd, (struct sockaddr *)&svrAdd, sizeof(svrAdd)) < 0) {
        std::cerr << "socketIn Cannot bind : port " << port << std::endl;
        return 0;
    }

    listen(listenFd, 5);

    len = sizeof(clntAdd);
    connFd = accept(listenFd, (struct sockaddr *)&clntAdd, &len);
    return (connFd);
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