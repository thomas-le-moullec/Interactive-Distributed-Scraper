//
// Created by tchikl_h on 4/20/17.
//

#include        "Phone.h"

Phone::Phone()
{
}

int             Phone::IsValidData(char const &c)
{
    return (c >= '0' && c <= '9');
}

int             Phone::FindData(int pos)
{
    pos = this->_fileContent.find("06", pos);
    int         save = pos;

    if (pos < 0)
        return (-1);
    pos += 2;
    for (int i = 0; i != 7 && pos < this->_fileContent.size() && this->IsValidData(this->_fileContent[save]); ++i)
        pos++;
    if (pos - save == 9)
        this->_data.push_back(this->_fileContent.substr(save, pos - save));
    return (pos);
}