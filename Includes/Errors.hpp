#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <iostream>
#include <stdexcept>

class RunTimeErrorController : public std::runtime_error
{
  private:
    std::string     _message;
  public:
    RunTimeErrorController(std::string const &message = "Error in Controller");
    RunTimeErrorController(const char * message= "Error in Controller");
    ~RunTimeErrorController() throw() {};
    const char* what() const throw() { return _message.c_str(); };
};

class RunTimeErrorModel : public std::runtime_error
{
private:
    std::string     _message;
public:
    RunTimeErrorModel(std::string const &message = "Error in Model");
    RunTimeErrorModel(const char * message= "Error in Model");
    ~RunTimeErrorModel() throw() {};
    const char* what() const throw() { return _message.c_str(); };
};

class RunTimeErrorView : public std::runtime_error
{
private:
    std::string     _message;
public:
    RunTimeErrorView(std::string const &message = "Error in View");
    RunTimeErrorView(const char * message= "Error in View");
    ~RunTimeErrorView() throw() {};
    const char* what() const throw() { return _message.c_str(); };
};

#endif //ERRORS_HPP_
