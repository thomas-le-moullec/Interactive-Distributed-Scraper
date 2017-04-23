#ifndef CPP_PLAZZA_CAESAR_HPP_
#define CPP_PLAZZA_CAESAR_HPP_

#include "AStrategyCipher.hpp"

namespace Plazza {
    class Caesar : public AStrategyCipher {
    private:
        std::string _fileContent;
        std::string executeCipher();

    public:
        virtual ~Caesar(){};
        Caesar(std::string const &);
    };
}

#endif //CPP_PLAZZA_CAESAR_H
