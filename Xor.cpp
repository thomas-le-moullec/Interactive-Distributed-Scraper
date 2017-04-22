#include "Xor.hpp"

Xor::Xor(std::string const &fileName) : ACipher(fileName)
{
}

int             Xor::executeCipher()
{
    std::string saveFileContent = this->_fileContent;
    for (int i = 0; i < 255; ++i) {
        for (int nb = 0; nb < this->_fileContent.size(); nb++) {
            this->_fileContent[nb] = saveFileContent[nb] ^ i;
        }
        if (this->unCiphered() != -1) {
            std::cout << "KEY = " << (char)i << " (" << i << ")" << std::endl;
            return (this->_fileContent);
        }
    }
    this->_fileContent = saveFileContent;
    for (int i = 0; i < 255; ++i) {
        for (int j = 0; j < 255; ++j) {
            for (int nb = 0; nb < this->_fileContent.size(); nb++) {
                if (nb % 2 == 0)
                    this->_fileContent[nb] = saveFileContent[nb] ^ i;
                else
                    this->_fileContent[nb] = saveFileContent[nb] ^ j;
            }
            if (this->unCiphered() != -1) {
                std::cout << "KEY = " << (char)i << (char)j << " (" << i << " | " << j << ")" << std::endl;
                return (this->_fileContent);
            }
        }
    }
    return (NULL);
}