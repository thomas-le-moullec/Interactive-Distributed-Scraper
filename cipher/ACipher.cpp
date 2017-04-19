//
// Created by tchikl_h on 4/18/17.
//

#include "ACipher.h"

ACipher::ACipher(std::string const &fileName) : _key(0), _fileContent(this->getFileContent(fileName))
{
}

std::string     ACipher::getFileContent(std::string const &fileName)
{
    std::string content;
    std::string line;
    std::ifstream myfile(fileName);
    if (myfile.is_open())
    {
        while (getline(myfile,line))
            content.append(line + "\n");
        myfile.close();
    }
    else
        std::cout << "Unable to open file" << std::endl;
    return (content);
}

int             ACipher::unCiphered()
{
    if (this->_fileContent.find("<HTML>", 0) != std::string::npos && this->_fileContent.find("</HTML>", 0) != std::string::npos)
        return (0);
    return (-1);
}