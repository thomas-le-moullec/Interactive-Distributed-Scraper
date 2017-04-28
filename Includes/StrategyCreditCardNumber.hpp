#ifndef STRATEGYCREDITCARDNUMBER_HPP_
#define STRATEGYCREDITCARDNUMBER_HPP_

#include "IStrategyInformation.hpp"
#include "Regex.hpp"

namespace Plazza {
    class StrategyCreditCardNumber : public IStrategyInformation {
    private:
        std::string _fileContent;
        std::vector<std::string> _information;

    public:
        virtual ~StrategyCreditCardNumber() {};
        StrategyCreditCardNumber();
        std::vector<std::string> execute(std::string const &fileContent);
        bool IsValidInformation(char const &);
        int  FindInformation(int);
        bool isValidCreditCardNumber(std::string const &);
    };
}

#endif
