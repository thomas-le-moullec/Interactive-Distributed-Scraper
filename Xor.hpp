#ifndef CPP_PLAZZA_XOR_HPP_
#define CPP_PLAZZA_XOR_HPP_

#include "AStrategyCipher.hpp"

namespace Plazza {
    class Xor : Plazza::AStrategyCipher {
    private:
        std::string _fileContent;
        std::string executeCipher();

    public:
        virtual ~Xor(){};
        Xor(std::string const &);
    };
}

#endif