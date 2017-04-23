//
// Created by tchikl_h on 4/20/17.
//

#include        "AData.h"

AData::AData()
{
}

void            AData::Execute()
{
    int         pos = 0;

    while (pos != -1) {
        pos = this->FindData(pos);
    }
    for (auto & it : this->_data)
    {
        std::cout << it << std::endl;
    }
}

void            AData::setFileContent(std::string const &fileContent)
{
    this->_fileContent = fileContent;
}