#ifndef STRATEGYPHONENUMBER_HPP_
#define STRATEGYPHONENUMBER_HPP_

#include "IStrategyInformation.hpp"

namespace Plazza {
    class StrategyPhoneNumber : Plazza::IStrategyInformation {
    private:
        std::string _fileContent;
        std::vector<std::string> _information;

        bool IsValidInformation(const char&);
        int  FindInformation(int);

    public:
        virtual ~StrategyPhoneNumber() {};
        StrategyPhoneNumber(std::string);
        void execute();
    };
}

#endif
