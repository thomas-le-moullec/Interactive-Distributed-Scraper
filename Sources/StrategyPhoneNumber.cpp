#include "StrategyPhoneNumber.hpp"

Plazza::StrategyPhoneNumber::StrategyPhoneNumber()
{
}

bool             Plazza::StrategyPhoneNumber::IsValidInformation(char const &c)
{
    return (c >= '0' && c <= '9');
}

bool            Plazza::StrategyPhoneNumber::isValidPhoneNumber(std::string const &str)
{
    for (unsigned int i = 0; i < str.length(); ++i)
    {
        if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
            return (false);
    }
    return (true);
}

int             Plazza::StrategyPhoneNumber::FindInformation(int pos)
{
    (void)pos;
    std::smatch m;
    std::regex  e("([0][0-9][\\ ]?([0-9]{2}[\\ ]?){3}[0-9]{2})");
    IRegex      *regex = new  Regex(e);

    while (regex->regexSearch(this->_fileContent, m)) {
        if (this->isValidPhoneNumber(m[0]))
            this->_information.push_back(m[0]);
        this->_fileContent = m.suffix().str();
    }
    return (pos);
}

std::vector<std::string>            Plazza::StrategyPhoneNumber::execute(std::string const &fileContent)
{
    this->_fileContent = fileContent;
    this->FindInformation(0);
    return _information;
}
