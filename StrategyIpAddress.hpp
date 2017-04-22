#ifndef STRATEGYIPADDRESS_HPP_
#define STRATEGYIPADDRESS_HPP_

#include "IStrategyInformation.hpp"

namespace Plazza {
    class StrategyIpAddress : Plazza::IStrategyInformation {
    private:
        std::string _fileContent;
        std::vector<std::string> _information;

        void execute();
        bool isValidInformation(char const &);
        int  FindInformation(int);

    public:
        virtual ~StrategyIpAddress() {};
        StrategyIpAddress(std::string);
    };
}

#endif //STRATEGYIPADDRESS_HPP_
