//
// Created by tchikl_h on 4/24/17.
//

#include "OpaqueType.h"

std::string &operator<<(std::string &str, orderBySocket const &order)
{
    IOpaqueType *opaque = new OpaqueType;
    return (opaque->Serialize(str, order));
}

orderBySocket &operator>>(std::string const &str, orderBySocket &order)
{
    IOpaqueType *opaque = new OpaqueType;
    return (opaque->UnSerialize(str, order));
}

int                 main()
{
    std::string     serialized;
    orderBySocket   order;
    orderBySocket   unSerialized;

    order.info = EMAIL_ADDRESS;
    order.fileName = "Default.html";
    serialized << order;
    std::cout << serialized << std::endl;
    serialized >> unSerialized;
    std::cout << "info = " << unSerialized.info << " fileName = " << unSerialized.fileName << std::endl;
    return (0);
}