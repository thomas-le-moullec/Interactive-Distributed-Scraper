#include "Xor.hpp"

Plazza::Xor::Xor() : AStrategyCipher()
{
}

std::string            Plazza::Xor::executeCipher(std::string const &fileName)
{
    try {
        _fileContent = this->getFileContent(fileName);
    }
    catch (RunTimeErrorController const &stdErr) {
        throw RunTimeErrorController("Couldn't open file : "+fileName);
    }
    std::string saveFileContent = _fileContent;
    for (int i = 0; i < 255; ++i) {
        if (this->isUnCiphered() == true) {
            return (this->_fileContent);
        }
        for (unsigned int nb = 0; nb < this->_fileContent.size(); nb++) {
            this->_fileContent[nb] = saveFileContent[nb] ^ i;
        }
    }
    this->_fileContent = saveFileContent;
    for (int i = 0; i < 255; ++i) {
        for (int j = 0; j < 255; ++j) {
            for (unsigned int nb = 0; nb < this->_fileContent.size(); nb++) {
                if (this->isUnCiphered() == true) {
                    return (this->_fileContent);
                }
                if (nb % 2 == 0)
                    this->_fileContent[nb] = saveFileContent[nb] ^ i;
                else
                    this->_fileContent[nb] = saveFileContent[nb] ^ j;
            }
        }
    }
    return (saveFileContent);
}
