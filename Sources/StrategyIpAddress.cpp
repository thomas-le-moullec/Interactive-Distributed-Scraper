#include "StrategyIpAddress.hpp"

Plazza::StrategyIpAddress::StrategyIpAddress()
{
}

bool             Plazza::StrategyIpAddress::IsValidInformation(char const &c)
{
    return (c >= '0' && c <= '9');
}

int             Plazza::StrategyIpAddress::FindInformation(int pos)
{
    pos = this->_fileContent.find(".", pos);
    int         save;
    int         val = 0;

    if (pos < 0)
        return (pos);
    if (pos > 0)
        pos--;
    for (int i = 0; pos > 0 && this->IsValidInformation(this->_fileContent[pos]) && i < 3; ++i)
        pos--;
    if (!this->IsValidInformation(this->_fileContent[pos]))
        pos++;
    save = pos;
    if (static_cast<unsigned int>(pos + 1) < this->_fileContent.length() && this->_fileContent[pos] == '0' && this->IsValidInformation(this->_fileContent[pos + 1]))
        val--;
    if (pos > 0 && !this->IsValidInformation(this->_fileContent[pos - 1]) && this->IsValidInformation(this->_fileContent[pos]) && atoi(&this->_fileContent[pos]) <= 255)
        val++;
    for (int i = 0; this->_fileContent[pos] && this->IsValidInformation(this->_fileContent[pos]) && i < 3; ++i)
        pos++;
    for (int nb = 0; nb < 3; ++nb)
    {
        if (this->_fileContent[pos] == '.')
            pos++;
        if (static_cast<unsigned int>(pos + 1) < this->_fileContent.length() && this->_fileContent[pos] == '0' && this->IsValidInformation(this->_fileContent[pos + 1]))
            val--;
        if (pos > 0 && this->_fileContent[pos - 1] == '.' && this->IsValidInformation(this->_fileContent[pos]) && atoi(&this->_fileContent[pos]) <= 255)
            val++;
        for (int i = 0; this->_fileContent[pos] && this->IsValidInformation(this->_fileContent[pos]) && i < 3; ++i)
            pos++;
    }
    if (val == 4)
        this->_information.push_back(this->_fileContent.substr(save, pos - save));
    return (pos);
}


std::vector<std::string>            Plazza::StrategyIpAddress::execute(std::string const &fileContent)
{
    int         pos = 0;

    this->_fileContent = fileContent;
    while (pos != -1)
        pos = this->FindInformation(pos);
    return _information;
}
