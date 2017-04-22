#ifndef CPP_PLAZZA_ASTRATEGYCIPHER_H
#define CPP_PLAZZA_ASTRATEGYCIPHER_H

#include "IStrategyCipher.hpp"

namespace Plazza {
    class AStrategyCipher : Plazza::IStrategyCipher {
    private:
        std::string _fileContent;
        virtual void executeCipher() = 0;
        virtual std::string getFileContent(std::string const &);
        virtual int unCiphered();

    public:
        virtual ~AStrategyCipher(){};
    protected:
        AStrategyCipher(std::string const &);
    };
}

#endif //CPP_PLAZZA_ASTRATEGYCIPHER_H
