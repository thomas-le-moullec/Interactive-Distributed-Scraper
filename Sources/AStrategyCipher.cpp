#include "AStrategyCipher.hpp"

Plazza::AStrategyCipher::AStrategyCipher()
{
}

std::string     Plazza::AStrategyCipher::getFileContent(std::string const &fileName)
{
    std::string content;
    std::string line;
    std::ifstream myfile(fileName);
    std::cout << "File Name GetContent" << fileName << std::endl;
    if (myfile.is_open())
    {
        while (getline(myfile,line)) {
            //std::cout << "MyFIle => " << line << std::endl;
            content.append(line + '\n');
        }
        myfile.close();
    }
    else
        std::cout << "Unable to open file" << std::endl;
    return (content);
}

bool             Plazza::AStrategyCipher::isUnCiphered()
{
    if (this->_fileContent.find("<HTML>", 0) != std::string::npos && this->_fileContent.find("</HTML>", 0) != std::string::npos)
        return (true);
    return (false);
}