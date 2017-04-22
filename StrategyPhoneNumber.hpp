#ifndef STRATEGYPHONENUMBER_HPP_
#define STRATEGYPHONENUMBER_HPP_

#include "IStrategyInformation.hpp"

namespace Plazza {
    class StrategyPhoneNumber : Plazza::IStrategyInformation {
    private:
        std::string _fileContent;
        std::vector<std::string> _information;

        void execute(std::string const &fileContent);
        bool isValidInformation(char const &);
        int  FindInformation(int);

    public:
        virtual ~StrategyPhoneNumber() {};
        StrategyPhoneNumber();
    };
}

#endif
