//
// Created by tchikl_h on 4/18/17.
//

#include        "ACipher.h"

ACipher::ACipher(IData *data, std::string const &fileName) : _data(data), _fileContent(this->getFileContent(fileName))
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
            content.append(line + '\n');
        myfile.close();
    }
    else
        std::cout << "Unable to open file" << std::endl;
    return (content);
}

int             ACipher::unCiphered()
{
    for (int i = 0; i < this->_fileContent.length(); ++i)
    {
        if (this->_fileContent[i] < 0 || this->_fileContent[i] > 127)
            return (-1);
    }
    return (0);
    /*if (this->_fileContent.find("<HTML>", 0) != std::string::npos && this->_fileContent.find("</HTML>", 0) != std::string::npos)
        return (0);*/
    return (-1);
}