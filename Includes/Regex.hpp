//
// Created by tchikl_h on 4/25/17.
//

#ifndef REGEX_H
#define REGEX_H

#include "IRegex.h"

class   Regex : public IRegex
{
private:
    std::regex  _pattern;
public:
    Regex(std::regex const &);
    virtual ~Regex() {};
    bool regexMatch(std::string const &);
    bool regexSearch(std::string, std::smatch &);
    std::string regexReplace(std::string const &, std::string const &);
};

#endif //REGEX_H
