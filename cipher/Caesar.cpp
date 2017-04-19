//
// Created by tchikl_h on 4/18/17.
//

#include "Caesar.h"

Caesar::Caesar(std::string const &fileName) : ACipher(fileName)
{
}

int             Caesar::isValidMail(char c)
{
    return (c >= '0' && c <= '9' ||
            c >= 'a' && c <= 'z' ||
            c >= 'A' && c <= 'Z' ||
            c == '-' || c == '_' || c == '.');
}

std::string     Caesar::findMail()
{
    int         pos = this->_fileContent.find("@", 0);
    int         save = pos;

    pos--;
    while (pos > 0 && this->isValidMail(this->_fileContent[pos]))
        pos--;
    pos++;
    save++;
    while (save < this->_fileContent.size() && this->isValidMail(this->_fileContent[save]))
        save++;
    if (pos < 0)
        return ("");
    return (this->_fileContent.substr(pos, save - pos));
}

int             Caesar::Cipher()
{
    for (int i = 0; i < 255; ++i)
    {
        if (this->unCiphered() != -1) {
            this->_key = i;
            std::cout << this->findMail() << std::endl;
            return (0);
        }
        for (int j = 0; j < this->_fileContent.size(); j++)
        {
            this->_fileContent[j]++;
        }
    }
    return (0);
}