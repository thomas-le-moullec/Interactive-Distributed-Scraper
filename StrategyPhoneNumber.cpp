#include "StrategyPhoneNumber.hpp"

StrategyPhoneNumber::StrategyPhoneNumber(std::string fileContent) : _fileContent(fileContent)
{
}

int             StrategyPhoneNumber::IsValidInformation(char const &c)
{
    return (c >= '0' && c <= '9');
}

int             StrategyPhoneNumber::FindInformation(int pos)
{
    pos = this->_fileContent.find("06", pos);
    int         save = pos;

    if (pos < 0)
        return (-1);
    pos += 2;
    for (int i = 0; i != 7 && pos < this->_fileContent.size() && this->IsValidInformation(this->_fileContent[save]); ++i)
        pos++;
    if (pos - save == 9)
        this->_information.push_back(this->_fileContent.substr(save, pos - save));
    return (pos);
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