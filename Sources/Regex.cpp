//
// Created by tchikl_h on 4/25/17.
//

#include "Regex.hpp"

Regex::Regex(std::regex const &pattern) : _pattern(pattern)
{
}

bool Regex::regexMatch(std::string const &str)
{
    return (regex_match(str, this->_pattern));
}

bool Regex::regexSearch(std::string str, std::smatch &m)
{
    return (regex_search(str, m, this->_pattern));
}

std::string Regex::regexReplace(std::string const &str, std::string const &newStr)
{
    return (regex_replace(str, this->_pattern, newStr));
}