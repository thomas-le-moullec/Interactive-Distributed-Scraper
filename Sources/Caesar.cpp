#include "Caesar.hpp"

Plazza::Caesar::Caesar()
{
}

std::string             Plazza::Caesar::executeCipher(std::string const &fileName)
{
    try {
        _fileContent = this->getFileContent(fileName);
    }
    catch (RunTimeErrorController const &stdErr) {
        throw RunTimeErrorController("Couldn't open file : "+fileName);
    }
    for (int i = 0; i < 255; ++i) {
        if (this->isUnCiphered() == true) {
            return (this->_fileContent);
        }
        for (unsigned int j = 0; j < this->_fileContent.size(); j++) {
            this->_fileContent[j]++;
        }
    }
    return (NULL);
}
