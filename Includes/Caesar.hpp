#ifndef CPP_PLAZZA_CAESAR_HPP_
#define CPP_PLAZZA_CAESAR_HPP_

#include "AStrategyCipher.hpp"

namespace Plazza {
    class Caesar : public AStrategyCipher {
    private:
        std::string _fileContent;

    public:
        std::string executeCipher(std::string const &);
        virtual ~Caesar(){};
        Caesar();
    };
}

#endif //CPP_PLAZZA_CAESAR_H
