#ifndef STRATEGYIPADDRESS_HPP_
#define STRATEGYIPADDRESS_HPP_

#include "IStrategyInformation.hpp"

namespace Plazza {
    class StrategyIpAddress : Plazza::IStrategyInformation {
    private:
        std::string _fileContent;
        std::vector<std::string> _information;

        bool IsValidInformation(const char &);
        int  FindInformation(int);

    public:
        virtual ~StrategyIpAddress() {};
        StrategyIpAddress(std::string);
        void execute();
    };
}

#endif //STRATEGYIPADDRESS_HPP_
