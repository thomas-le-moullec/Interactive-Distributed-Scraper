//
// Created by tchikl_h on 4/20/17.
//

#ifndef                         MAIL_H
#define                         MAIL_H

#include                        "AData.h"

class                           Mail : public AData
{
public:
    Mail();
    virtual ~Mail() {};
    int                         IsValidData(char const &);
    int                         FindData(int);
};

#endif                          //MAIL_H
