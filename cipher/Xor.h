//
// Created by tchikl_h on 4/18/17.
//

#ifndef                 XOR_CPP_H
#define                 XOR_CPP_H

#include                "ACipher.h"

class                   Xor : public ACipher
{
public:
    Xor(IData *, std::string const &);
    virtual ~Xor() {};
    int                 Cipher();
};

#endif                  //XOR_CPP_H
