#ifndef STRATEGYEMAILADDRESS_HPP_
#define STRATEGYEMAILADDRESS_HPP_

#include "IStrategyInformation.hpp"

namespace Plazza {
    class StrategyEmailAddress : Plazza::IStrategyInformation {
    private:
        void execute(std::string file);
        bool isValidInformation(char const &);
        int  FindInformation(int);

    public:
        virtual ~StrategyEmailAddress() {};
        StrategyEmailAddress();
    };
}

#endif //STRATEGYEMAILADDRESS_HPP_
