//
// Created by tchikl_h on 4/20/17.
//

#include        "Ip.h"

Ip::Ip()
{
}

int             Ip::IsValidData(char const &c)
{
    return (c >= '0' && c <= '9');
}

int             Ip::FindData(int pos)
{
    pos = this->_fileContent.find(".", pos);
    int         save;
    int         val = 0;

    if (pos < 0)
        return (pos);
    if (pos > 0)
        pos--;
    for (int i = 0; pos > 0 && this->IsValidData(this->_fileContent[pos]) && i < 3; ++i)
        pos--;
    if (!this->IsValidData(this->_fileContent[pos]))
        pos++;
    save = pos;
    if (pos + 1 < this->_fileContent.length() && this->_fileContent[pos] == '0' && this->IsValidData(this->_fileContent[pos + 1]))
        val--;
    if (pos > 0 && !this->IsValidData(this->_fileContent[pos - 1]) && this->IsValidData(this->_fileContent[pos]) && atoi(&this->_fileContent[pos]) <= 255)
        val++;
    for (int i = 0; this->_fileContent[pos] && this->IsValidData(this->_fileContent[pos]) && i < 3; ++i)
        pos++;
    for (int nb = 0; nb < 3; ++nb)
    {
        if (this->_fileContent[pos] == '.')
            pos++;
        if (pos + 1 < this->_fileContent.length() && this->_fileContent[pos] == '0' && this->IsValidData(this->_fileContent[pos + 1]))
            val--;
        if (pos > 0 && this->_fileContent[pos - 1] == '.' && this->IsValidData(this->_fileContent[pos]) && atoi(&this->_fileContent[pos]) <= 255)
            val++;
        for (int i = 0; this->_fileContent[pos] && this->IsValidData(this->_fileContent[pos]) && i < 3; ++i)
            pos++;
    }
    if (val == 4)
        this->_data.push_back(this->_fileContent.substr(save, pos - save));
    return (pos);
}