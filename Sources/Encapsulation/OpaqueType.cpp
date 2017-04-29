//
// Created by tchikl_h on 4/24/17.
//

#include            "OpaqueType.hpp"

Plazza::Controller::OpaqueType::OpaqueType()
{
}

std::string         &Plazza::Controller::operator<<(std::string &str, Plazza::Controller::orderBySocket const &order)
{
    Plazza::Controller::IOpaqueType *opaque = new Plazza::Controller::OpaqueType;
    return (opaque->Serialize(str, order));
}

Plazza::Controller::orderBySocket       &Plazza::Controller::operator>>(std::string const &str, Plazza::Controller::orderBySocket &order)
{
    Plazza::Controller::IOpaqueType *opaque = new Plazza::Controller::OpaqueType;
    return (opaque->UnSerialize(str, order));
}

std::string          &Plazza::Controller::OpaqueType::Serialize(std::string &str, Plazza::Controller::orderBySocket const &order)
{
    std::ostringstream    convert;
    convert << order.info << order.fileName;
    str.append(convert.str());
    return (str);
}
Plazza::Controller::orderBySocket        &Plazza::Controller::OpaqueType::UnSerialize(std::string const &str, Plazza::Controller::orderBySocket &order)
{
    order.info = static_cast<Plazza::Controller::Information>(atoi(str.c_str()));
    order.fileName = &str[1];
    return order;
}
