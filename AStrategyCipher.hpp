#ifndef CPP_PLAZZA_ASTRATEGYCIPHER_HPP_
#define CPP_PLAZZA_ASTRATEGYCIPHER_HPP_

#include "IStrategyCipher.hpp"
#include <fstream>

namespace Plazza {
    class AStrategyCipher : public IStrategyCipher {
    private:
        virtual std::string executeCipher() = 0;
        virtual std::string getFileContent(std::string const &);

    public:
        virtual ~AStrategyCipher(){};
        virtual bool isUnCiphered();
    protected:
        AStrategyCipher(std::string const &);
        std::string         _fileContent;
    };
}

#endif //CPP_PLAZZA_ASTRATEGYCIPHER_HPP_
