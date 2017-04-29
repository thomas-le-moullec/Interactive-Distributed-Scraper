#include "Atbash.hpp"

Plazza::Atbash::Atbash() : AStrategyCipher()
{
}

std::string            Plazza::Atbash::executeCipher(std::string const &fileName)
{
    try {
        _fileContent = this->getFileContent(fileName);
    }
    catch (RunTimeErrorController const &stdErr) {
        throw RunTimeErrorController("Couldn't open file : "+fileName);
    }
    std::string saveFileContent = _fileContent;
    for (unsigned int nb = 0; nb < this->_fileContent.size(); nb++) {
        if (this->_fileContent[nb] >= 0 && this->_fileContent[nb] < 127)
            this->_fileContent[nb] = 127 - this->_fileContent[nb];
    }
    if (this->isUnCiphered() == true)
        return (this->_fileContent);
    this->_fileContent = saveFileContent;
    return ("");
}
