//
// Created by tchikl_h on 4/20/17.
//

#ifndef             IDATA_H
#define             IDATA_H

#include            <iostream>

class               IData
{
public:
    virtual ~IData() {};
    virtual void    Execute() = 0;
    virtual void    setFileContent(std::string const &) = 0;
    virtual int     IsValidData(char const &) = 0;
    virtual int     FindData(int) = 0;
};

#endif              //IDATA_H
