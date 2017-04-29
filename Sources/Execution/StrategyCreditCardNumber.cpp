#include "StrategyCreditCardNumber.hpp"

Plazza::StrategyCreditCardNumber::StrategyCreditCardNumber()
{
}

bool             Plazza::StrategyCreditCardNumber::IsValidInformation(char const &c)
{
    return (c >= '0' && c <= '9');
}

bool            Plazza::StrategyCreditCardNumber::isValidCreditCardNumber(std::string const &str)
{
    for (unsigned int i = 0; i < str.length(); ++i)
    {
        if ((str[i] < '0' || str[i] > '9') && str[i] != ' ' && str[i] != '\0') {
            return (false);
        }
    }
    return (true);
}

int             Plazza::StrategyCreditCardNumber::FindInformation(int pos)
{
    pos = this->_fileContent.find("4", pos);
    int         save;

    save = pos;
    if (pos < 0)
        return (pos);
    pos++;
    for (int i = 0; i < 3 && (unsigned int)pos < this->_fileContent.length() && this->IsValidInformation(this->_fileContent[pos]); ++i)
        pos++;
    if ((unsigned int)pos < this->_fileContent.length() && this->_fileContent[pos] == ' ')
        pos++;
    for (int i = 0; i < 4 && (unsigned int)pos < this->_fileContent.length() && this->IsValidInformation(this->_fileContent[pos]); ++i)
        pos++;
    if ((unsigned int)pos < this->_fileContent.length() && this->_fileContent[pos] == ' ')
        pos++;
    for (int i = 0; i < 4 && (unsigned int)pos < this->_fileContent.length() && this->IsValidInformation(this->_fileContent[pos]); ++i)
        pos++;
    if ((unsigned int)pos < this->_fileContent.length() && this->_fileContent[pos] == ' ')
        pos++;
    for (int i = 0; i < 4 && (unsigned int)pos < this->_fileContent.length() && this->IsValidInformation(this->_fileContent[pos]); ++i)
        pos++;
    if (pos - save >= 16)
        this->_information.push_back(this->_fileContent.substr(save, pos - save));
    return (pos);
}

std::vector<std::string>            Plazza::StrategyCreditCardNumber::execute(std::string const &fileContent)
{
    int pos = 0;
    this->_fileContent = fileContent;
    while (pos != -1)
        pos = this->FindInformation(pos);
    return _information;
}
