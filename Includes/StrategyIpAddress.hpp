#ifndef STRATEGYIPADDRESS_HPP_
#define STRATEGYIPADDRESS_HPP_

#include "IStrategyInformation.hpp"

namespace Plazza {
    class StrategyIpAddress : public IStrategyInformation {
    private:
        std::string _fileContent;
        std::vector<std::string> _information;

    public:
        virtual ~StrategyIpAddress() {};
        StrategyIpAddress();
        std::vector<std::string> execute(std::string const &fileContent);
        bool IsValidInformation(const char &);
        int  FindInformation(int);
    };
}

#endif //STRATEGYIPADDRESS_HPP_
