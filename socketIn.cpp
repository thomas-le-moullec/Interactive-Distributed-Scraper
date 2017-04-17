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
using namespace std;

void *task1(void *);

int socketIn(int port) {
    int portNo;
    int listenFd, connFd;
    socklen_t len; //store size of the address
    struct sockaddr_in svrAdd, clntAdd;

    //pthread_t threadA[3];
    portNo = port;
    //portNo = atoi(port.c_str());

    if ((portNo > 65535) || (portNo < 2000)) {
        cerr << "Please enter a port number between 2000 - 65535" << endl;
        return 0;
    }
    //std::cout << port << std::endl;
    //create socket
    listenFd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenFd < 0) {
        cerr << "Cannot open socket" << endl;
        return 0;
    }

    bzero((char *) &svrAdd, sizeof(svrAdd));

    svrAdd.sin_family = AF_INET;
    svrAdd.sin_addr.s_addr = INADDR_ANY;
    svrAdd.sin_port = htons(portNo);

    //bind socket
    if (bind(listenFd, (struct sockaddr *) &svrAdd, sizeof(svrAdd)) < 0) {
        cerr << "Cannot bind1" << endl;
        return 0;
    }

    listen(listenFd, 5);

    connFd = accept(listenFd, (struct sockaddr *) &clntAdd, &len);

    len = sizeof(clntAdd);
    return (connFd);
}

std::string     receiveMessage(int connFd)
{
    char test[300];
    bzero(test, 301);
    read(connFd, test, 300);

    string tester (test);

    //close(connFd);
    if (tester[0] == '\0')
        return ("");
    return (tester);
}