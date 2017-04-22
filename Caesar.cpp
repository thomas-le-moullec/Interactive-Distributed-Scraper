#include "Caesar.hpp"

Caesar::Caesar(std::string const &fileName) : ACipher(fileName)
{
}

std::string             Caesar::executeCipher()
{
    for (int i = 0; i < 255; ++i) {
        if (this->unCiphered() != -1) {
            std::cout << "KEY = " << (char)i << " (" << i << ")" << std::endl;
            return (this->_fileContent);
        }
        for (int j = 0; j < this->_fileContent.size(); j++) {
            this->_fileContent[j]++;
        }
    }
    return (NULL);
}