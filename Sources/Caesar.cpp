#include "Caesar.hpp"

Plazza::Caesar::Caesar()
{
}

std::string             Plazza::Caesar::executeCipher(std::string const &fileName)
{
    _fileContent = this->getFileContent(fileName);
    for (int i = 0; i < 255; ++i) {
        if (this->isUnCiphered() == true) {
            std::cout << "KEY = " << (char)i << " (" << i << ")" << std::endl;
            return (this->_fileContent);
        }
        for (int j = 0; j < this->_fileContent.size(); j++) {
            this->_fileContent[j]++;
        }
    }
    return (NULL);
}