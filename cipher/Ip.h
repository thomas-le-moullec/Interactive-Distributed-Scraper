//
// Created by tchikl_h on 4/20/17.
//

#ifndef                         IP_H
#define                         IP_H

#include                        "AData.h"

class                           Ip : public AData
{
public:
    Ip();
    virtual ~Ip() {};
    int                         IsValidData(char const &);
    int                         FindData(int);
};

#endif                          //IP_H
