#ifndef XOR_HPP_
# define XOR_HPP_

#include "AStrategyCipher.hpp"

namespace Plazza {
    class Xor : Plazza::AStrategyCipher {
    private:
        std::string _fileContent;
        void executeCipher();

    public:
        virtual ~Xor(){};
        Xor();
    };
}

#endif