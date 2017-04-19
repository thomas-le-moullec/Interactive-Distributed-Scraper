//
// Created by tchikl_h on 4/18/17.
//

#include "ICipher.h"
#include "Caesar.h"
#include "Xor.h"

int                 main()
{
    ICipher         *cipher = new Xor("testXor.html");

    cipher->Cipher();
    return (0);
}