#ifndef SERIALIZE_IOPAQUETYPE_HPP_
#define SERIALIZE_IOPAQUETYPE_HPP_

#include <iostream>
#include <ostream>
#include <sstream>

#include "Order.hpp"

namespace Plazza {
    namespace Controller {
        class IOpaqueType {
        public:
            virtual ~IOpaqueType() {};
            virtual std::string &Serialize(std::string &, orderBySocket const &) = 0;
            virtual orderBySocket &UnSerialize(std::string const &, orderBySocket &) = 0;
        };
    }
}

#endif //SERIALIZE_IOPAQUETYPE_HPP_
