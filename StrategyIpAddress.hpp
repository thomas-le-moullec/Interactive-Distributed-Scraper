#ifndef STRATEGYIPADDRESS_HPP_
#define STRATEGYIPADDRESS_HPP_

#include "IStrategyInformation.hpp"

namespace Plazza {
    class StrategyIpAddress : Plazza::IStrategyInformation {
    private:
        void execute(std::string file);
        bool isValidInformation(char const &);
        int  FindInformation(int);

    public:
        virtual ~StrategyIpAddress() {};
        StrategyIpAddress();
    };
}

#endif //STRATEGYIPADDRESS_HPP_
