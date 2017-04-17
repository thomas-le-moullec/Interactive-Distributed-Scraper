//
// Created by tchikl_h on 4/13/17.
//

#include <string.h>
#include <cstring>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <strings.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>
#include <errno.h>

int socketChild(int port) {
    int portNo;
    int listenFd;
    struct sockaddr_in svrAdd;
    struct hostent *server;

    portNo = port;

    if ((portNo > 65535) || (portNo < 2000)) {
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

    svrAdd.sin_port = htons(portNo);

    int checker = connect(listenFd, (struct sockaddr *)&svrAdd, sizeof(svrAdd));

    if (checker < 0) {
        std::cerr << "socketOut Cannot connect! : port " << port << std::endl;
        return 0;
    }
    return (listenFd);
}

void    sendMessage(std::string message, int socketFd)
{
    write(socketFd, message.c_str(), strlen(message.c_str()));
}