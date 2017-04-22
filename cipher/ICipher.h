//
// Created by tchikl_h on 4/18/17.
//

#ifndef                 ICIPHER_H
#define                 ICIPHER_H

#include <iostream>
#include <fstream>

class                   ICipher
{
public:
    virtual ~ICipher() {};
    virtual int Cipher() = 0;
};

#endif                  //ICIPHER_H
