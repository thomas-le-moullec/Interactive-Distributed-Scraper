#ifndef CPP_PLAZZA_XOR_HPP_
#define CPP_PLAZZA_XOR_HPP_

#include "AStrategyCipher.hpp"

namespace Plazza {
    class Xor : public AStrategyCipher {
    private:
        std::string _fileContent;

    public:
        std::string executeCipher();
        virtual ~Xor(){};
        Xor(std::string const &);
    };
}

#endif
