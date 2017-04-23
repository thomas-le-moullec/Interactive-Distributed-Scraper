//
// Created by tchikl_h on 4/18/17.
//

#ifndef                 CAESAR_H
#define                 CAESAR_H

#include                "ACipher.h"

class                   Caesar : public ACipher
{
public:
    Caesar(IData *, std::string const &);
    virtual ~Caesar() {};
    int                 Cipher();
};

#endif                  //CAESAR_H
