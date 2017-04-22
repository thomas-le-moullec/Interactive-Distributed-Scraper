#ifndef STRATEGYEMAILADDRESS_HPP_
#define STRATEGYEMAILADDRESS_HPP_

#include "IStrategyInformation.hpp"

namespace Plazza {
    class StrategyEmailAddress : Plazza::IStrategyInformation {
    private:
        std::string _fileContent;
        std::vector<std::string> _information;

    public:
        virtual ~StrategyEmailAddress() {};
        void execute(std::string const &fileContent);
        bool isValidInformation(char const &);
        int  FindInformation(int);
        StrategyEmailAddress();
    };
}

#endif //STRATEGYEMAILADDRESS_HPP_
