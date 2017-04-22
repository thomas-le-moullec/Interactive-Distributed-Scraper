#ifndef STRATEGYIPADDRESS_HPP_
#define STRATEGYIPADDRESS_HPP_

#include "IStrategyInformation.hpp"

namespace Plazza {
    class StrategyIpAddress : Plazza::IStrategyInformation {
    private:
        std::string _fileContent;
        std::vector<std::string> _information;

        void execute(std::string const &fileContent);
        bool isValidInformation(char const &);
        int  FindInformation(int);

    public:
        virtual ~StrategyIpAddress() {};
        StrategyIpAddress();
    };
}

#endif //STRATEGYIPADDRESS_HPP_
