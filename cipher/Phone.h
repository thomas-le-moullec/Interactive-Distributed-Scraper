//
// Created by tchikl_h on 4/20/17.
//

#ifndef                         PHONE_H
#define                         PHONE_H

#include                        "AData.h"

class                           Phone : public AData
{
public:
    Phone();
    virtual ~Phone() {};
    int                         IsValidData(char const &);
    int                         FindData(int);
};

#endif                          //PHONE_H
