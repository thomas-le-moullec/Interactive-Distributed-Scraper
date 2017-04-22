//
// Created by tchikl_h on 4/18/17.
//

#include "ICipher.h"
#include "Caesar.h"
#include "Xor.h"
#include "Mail.h"
#include "Phone.h"
#include "Ip.h"

int                 main(int ac, char **av)
{
    if (ac != 4)
        return (-1);
    ICipher         *cipher;
    std::string     type(av[1]);
    std::string     data(av[2]);

    if (type == "caesar") {
        if (data == "mail")
            cipher = new Caesar(new Mail(), av[3]);
        if (data == "phone")
            cipher = new Caesar(new Phone(), av[3]);
        if (data == "ip")
            cipher = new Caesar(new Ip(), av[3]);
    }
    if (type == "xor") {
        if (data == "mail")
            cipher = new Xor(new Mail(), av[3]);
        if (data == "phone")
            cipher = new Xor(new Phone(), av[3]);
        if (data == "ip")
            cipher = new Xor(new Ip(), av[3]);
    }
    cipher->Cipher();
    return (0);
}