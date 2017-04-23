//
// Created by tchikl_h on 4/20/17.
//

#include        "Mail.h"

Mail::Mail()
{
}

int             Mail::IsValidData(char const &c)
{
    return (c >= '0' && c <= '9' ||
            c >= 'a' && c <= 'z' ||
            c >= 'A' && c <= 'Z' ||
            c == '-' || c == '_' || c == '.');
}

int             Mail::FindData(int pos)
{
    pos = this->_fileContent.find("@", pos);
    int         save = pos;

    if (pos < 0)
        return (-1);
    if (pos > 0)
        pos--;
    while (pos > 0 && this->IsValidData(this->_fileContent[pos]))
        pos--;
    if (pos != 0)
        pos++;
    save++;
    while (save < this->_fileContent.size() && this->IsValidData(this->_fileContent[save]))
        save++;
    this->_data.push_back(this->_fileContent.substr(pos, save - pos));
    return (save);
}