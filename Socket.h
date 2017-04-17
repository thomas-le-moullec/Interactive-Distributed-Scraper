//
// Created by tchikl_h on 4/17/17.
//

#ifndef                 SOCKET_H
#define                 SOCKET_H

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
//#include <string>

class                   Socket
{
private:
    int                 _port;
public:
    Socket(int);
    ~Socket() {};
    int                 socketChild();
    int                 socketParent();
};

#endif                  //SOCKET_H
