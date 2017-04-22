#ifndef STRATEGYEMAILADDRESS_HPP_
#define STRATEGYEMAILADDRESS_HPP_

#include "IStrategyInformation.hpp"

namespace Plazza {
    class StrategyEmailAddress : Plazza::IStrategyInformation {
    private:
        std::string _fileContent;
        std::vector<std::string> _information;

        void execute();
        bool isValidInformation(char const &);
        int  FindInformation(int);

    public:
        virtual ~StrategyEmailAddress() {};
        StrategyEmailAddress(std::string cont &);
    };
}

#endif //STRATEGYEMAILADDRESS_HPP_
