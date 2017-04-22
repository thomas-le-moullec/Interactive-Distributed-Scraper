#ifndef CPP_PLAZZA_CAESAR_H
#define CPP_PLAZZA_CAESAR_H

#include "AStrategyCipher.hpp"

namespace Plazza {
    class Caesar : Plazza::AStrategyCipher {
    private:
        std::string _fileContent;
        void executeCipher();

    public:
        virtual ~Caesar(){};
        Caesar();
    };
}

#endif //CPP_PLAZZA_CAESAR_H
