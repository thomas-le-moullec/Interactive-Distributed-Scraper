//
// Created by tchikl_h on 4/25/17.
//

#ifndef IREGEX_H
#define IREGEX_H

#include <iostream>
#include <regex>

class   IRegex
{
public:
    virtual ~IRegex() {};
    virtual bool regexMatch(std::string const &) = 0;
    virtual bool regexSearch(std::string, std::smatch &) = 0;
    virtual std::string regexReplace(std::string const &, std::string const &) = 0;
};

#endif //IREGEX_H
