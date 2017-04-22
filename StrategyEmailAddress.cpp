#include "StrategyEmailAddress.hpp"

StrategyEmailAddress::StrategyEmailAddress(std::string fileContent) : _fileContent(fileContent)
{
}

int             StrategyEmailAddress::IsValidInformation(char const &c)
{
    return (c >= '0' && c <= '9' ||
            c >= 'a' && c <= 'z' ||
            c >= 'A' && c <= 'Z' ||
            c == '-' || c == '_' || c == '.');
}

int             StrategyEmailAddress::FindInformation(int pos)
{
    pos = this->_fileContent.find("@", pos);
    int         save = pos;

    if (pos < 0)
        return (-1);
    if (pos > 0)
        pos--;
    while (pos > 0 && this->IsValidInformation(this->_fileContent[pos]))
        pos--;
    if (pos != 0)
        pos++;
    save++;
    while (save < this->_fileContent.size() && this->IsValidInformation(this->_fileContent[save]))
        save++;
    this->_Information.push_back(this->_fileContent.substr(pos, save - pos));
    return (save);
}


void            StrategyPhoneNumber::Execute()
{
    int         pos = 0;

    while (pos != -1)
        pos = this->FindInformation(pos);
    for (auto & it : this->_information)
    {
        std::cout << it << std::endl;
    }
}