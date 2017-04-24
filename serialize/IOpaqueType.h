//
// Created by tchikl_h on 4/24/17.
//

#ifndef SERIALIZE_IOPAQUETYPE_H
#define SERIALIZE_IOPAQUETYPE_H

#include <iostream>
#include <ostream>
#include <sstream>

enum                Information
{
    PHONE_NUMBER,
    EMAIL_ADDRESS,
    IP_ADDRESS
};

struct              orderBySocket
{
    Information     info;
    std::string     fileName;
};

class IOpaqueType
{
public:
    virtual ~IOpaqueType() {};
    virtual std::string          &Serialize(std::string &, orderBySocket const &) = 0;
    virtual orderBySocket        &UnSerialize(std::string const &, orderBySocket &) = 0;
};

#endif //SERIALIZE_IOPAQUETYPE_H
