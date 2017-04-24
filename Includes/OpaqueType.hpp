#ifndef SERIALIZE_OPAQUETYPE_HPP_
#define SERIALIZE_OPAQUETYPE_HPP_

#include "IOpaqueType.hpp"

namespace Plazza {
    namespace Controller {
        class OpaqueType : public IOpaqueType {
        public:
            OpaqueType();
            ~OpaqueType() {};
            std::string &Serialize(std::string &, Plazza::Controller::orderBySocket const &);
            orderBySocket &UnSerialize(std::string const &, Plazza::Controller::orderBySocket &);
        };

        std::string &operator<<(std::string &, Plazza::Controller::orderBySocket const &);
        orderBySocket &operator>>(std::string const &, Plazza::Controller::orderBySocket &);
    }
}

#endif //SERIALIZE_OPAQUETYPE_HPP_
