#ifndef XOR_HPP_
# define XOR_HPP_

#include <iostream>

namespace Plazza {
    class IStrategyCipher {
    private:
        virtual void executeCipher() = 0;

    public:
        virtual ~IStrategyCipher(){};
    };
}

#endif