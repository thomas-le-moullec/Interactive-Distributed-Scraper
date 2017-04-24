//
// Created by tchikl_h on 4/24/17.
//

#include "OpaqueType.h"

OpaqueType::OpaqueType()
{
}

std::string          &OpaqueType::Serialize(std::string &str, orderBySocket const &order)
{
    std::ostringstream    convert;
    convert << order.info << order.fileName;
    str.append(convert.str());
    return (str);
}
orderBySocket        &OpaqueType::UnSerialize(std::string const &str, orderBySocket &order)
{
    order.info = static_cast<Information>(atoi(str.c_str()));
    order.fileName = &str[1];
    return order;
}