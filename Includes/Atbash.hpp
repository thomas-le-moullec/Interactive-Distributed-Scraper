#ifndef CPP_PLAZZA_ATBASH_HPP_
#define CPP_PLAZZA_ATBASH_HPP_

#include "AStrategyCipher.hpp"

namespace Plazza {
    class Atbash : public AStrategyCipher {

    public:
        std::string executeCipher(std::string const &);
        virtual ~Atbash(){};
        Atbash();
    };
}

#endif
