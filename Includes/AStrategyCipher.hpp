#ifndef CPP_PLAZZA_ASTRATEGYCIPHER_HPP_
#define CPP_PLAZZA_ASTRATEGYCIPHER_HPP_

#include "IStrategyCipher.hpp"
#include <fstream>

namespace Plazza {
    class AStrategyCipher : public IStrategyCipher {

    public:
        virtual std::string executeCipher(std::string const &) = 0;
        virtual std::string getFileContent(std::string const &);
        virtual ~AStrategyCipher(){};
        virtual bool isUnCiphered();
    protected:
        AStrategyCipher();
        std::string         _fileContent;
    };
}

#endif //CPP_PLAZZA_ASTRATEGYCIPHER_HPP_
