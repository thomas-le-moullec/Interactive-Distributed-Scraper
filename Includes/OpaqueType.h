//
// Created by tchikl_h on 4/24/17.
//

#ifndef SERIALIZE_OPAQUETYPE_H
#define SERIALIZE_OPAQUETYPE_H

#include "IOpaqueType.h"

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

#endif //SERIALIZE_OPAQUETYPE_H
