//
// Created by tchikl_h on 4/20/17.
//

#ifndef             ADATA_H
#define             ADATA_H

#include            <vector>
#include            "IData.h"

class               AData : public IData
{
protected:
    std::string                 _fileContent;
    std::vector<std::string>    _data;
public:
    AData();
    virtual ~AData() {};
    void            Execute();
    void            setFileContent(std::string const &);
    virtual int     IsValidData(char const &) = 0;
    virtual int     FindData(int) = 0;
};

#endif              //ADATA_H
