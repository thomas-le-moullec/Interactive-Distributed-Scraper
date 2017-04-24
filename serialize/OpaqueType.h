//
// Created by tchikl_h on 4/24/17.
//

#ifndef SERIALIZE_OPAQUETYPE_H
#define SERIALIZE_OPAQUETYPE_H

#include "IOpaqueType.h"

class               OpaqueType : public IOpaqueType{
public:
    OpaqueType();
    ~OpaqueType() {};
    std::string          &Serialize(std::string &, orderBySocket const &);
    orderBySocket        &UnSerialize(std::string const &, orderBySocket &);
};


#endif //SERIALIZE_OPAQUETYPE_H
