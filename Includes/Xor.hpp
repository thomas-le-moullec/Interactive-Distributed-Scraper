#ifndef CPP_PLAZZA_XOR_HPP_
#define CPP_PLAZZA_XOR_HPP_

#include "AStrategyCipher.hpp"

namespace Plazza {
    class Xor : public AStrategyCipher {

    public:
        std::string executeCipher(std::string const &);
        virtual ~Xor(){};
        Xor();
    };
}

#endif
