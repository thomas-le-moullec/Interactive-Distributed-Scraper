//
// Created by tchikl_h on 4/19/17.
//

#ifndef                 PROCESSMANAGERSOCKETS_H
#define                 PROCESSMANAGERSOCKETS_H

#include                <iostream>
#include                <string.h>
#include                <stdio.h>
#include                <unistd.h>
#include                <sys/types.h>
#include                <sys/wait.h>
#include                <sys/socket.h>
#include                "Socket.h"

class                   ProcessManagerSockets
{
private:
    std::vector<int>    _fdProcess;
public:
    ProcessManagerSockets();
    ~ProcessManagerSockets() {};
    int                 addProcess(Socket *);
};

#endif                  //PROCESSMANAGERSOCKETS_H
