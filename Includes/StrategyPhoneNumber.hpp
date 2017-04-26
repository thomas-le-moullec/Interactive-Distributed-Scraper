#ifndef STRATEGYPHONENUMBER_HPP_
#define STRATEGYPHONENUMBER_HPP_

#include "IStrategyInformation.hpp"
#include "Regex.hpp"

namespace Plazza {
    class StrategyPhoneNumber : public IStrategyInformation {
    private:
        std::string _fileContent;
        std::vector<std::string> _information;

    public:
        virtual ~StrategyPhoneNumber() {};
        StrategyPhoneNumber();
        std::vector<std::string> execute(std::string const &fileContent);
        bool IsValidInformation(char const &);
        int  FindInformation(int);
        bool isValidPhoneNumber(std::string const &);
    };
}

#endif
