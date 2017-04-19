//
// Created by tchikl_h on 4/18/17.
//

#ifndef                 ACIPHER_H
#define                 ACIPHER_H

#include                "ICipher.h"

class                   ACipher : public ICipher
{
protected:
    char                _key;
    std::string         _fileContent;
public:
    ACipher(std::string const &);
    virtual ~ACipher() {};
    virtual int Cipher() = 0;
    std::string         getFileContent(std::string const &);
    int                 unCiphered();
};

#endif                  //ACIPHER_H
