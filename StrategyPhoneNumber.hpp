#ifndef STRATEGYPHONENUMBER_HPP_
# define STRATEGYPHONENUMBER_HPP_

#include "IStrategyInformation.hpp"

namespace Plazza {
    class StrategyPhoneNumber : Plazza::IStrategyInformation {
    private:
        void execute(std::string file);
        bool isValidInformation(char const &);
        int  FindInformation(int);

    public:
        virtual ~StrategyPhoneNumber() {};
        StrategyPhoneNumber();
    };
}

#endif
