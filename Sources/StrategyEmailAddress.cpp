#include "StrategyEmailAddress.hpp"

Plazza::StrategyEmailAddress::StrategyEmailAddress()
{
}

bool             Plazza::StrategyEmailAddress::IsValidInformation(char const &c)
{
    return ((c >= '0' && c <= '9') ||
            (c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            c == '-' || c == '_' || c == '.');
}

int             Plazza::StrategyEmailAddress::FindInformation(int pos)
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
    while (static_cast<unsigned int>(save) < this->_fileContent.size() && this->IsValidInformation(this->_fileContent[save]))
        save++;
    if (save > 0 && this->_fileContent[pos] != '@' && this->_fileContent[save - 1] != '@')
        this->_information.push_back(this->_fileContent.substr(pos, save - pos));
    return (save);
}


std::vector<std::string>            Plazza::StrategyEmailAddress::execute(std::string const &fileContent)
{
    int         pos = 0;

    this->_fileContent = fileContent;
    while (pos != -1)
        pos = this->FindInformation(pos);
    return _information;
}
