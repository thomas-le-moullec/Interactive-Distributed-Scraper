#include "AStrategyCipher.hpp"

Plazza::AStrategyCipher::AStrategyCipher()
{
}

std::string     Plazza::AStrategyCipher::getFileContent(std::string const &fileName)
{
    std::string content;
    std::string line;
    std::ifstream myfile(fileName);
    if (myfile.is_open())
    {
        while (getline(myfile,line)) {
            content.append(line + '\n');
        }
        myfile.close();
    }
    else
        throw RunTimeErrorController("Couldn't open file : "+fileName);
    return (content);
}

bool             Plazza::AStrategyCipher::isUnCiphered()
{
    if (this->_fileContent.find("<HTML>", 0) != std::string::npos && this->_fileContent.find("</HTML>", 0) != std::string::npos)
        return (true);
    return (false);
}
