//
// Created by tchikl_h on 4/18/17.
//

#ifndef                 XOR_CPP_H
#define                 XOR_CPP_H

#include                "ACipher.h"

class                   Xor : public ACipher
{
public:
    Xor(std::string const &);
    virtual ~Xor() {};
    int                 Cipher();
    std::string         findMail();
    int                 isValidMail(char);
};

#endif                  //XOR_CPP_H
