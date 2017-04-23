//
// Created by tchikl_h on 4/18/17.
//

#include "Xor.h"

Xor::Xor(IData *data, std::string const &fileName) : ACipher(data, fileName)
{
}

int             Xor::Cipher()
{
    std::string saveFileContent = this->_fileContent;
    std::string saveFileContent = this->_fileContent;
    for (int i = 0; i < 255; ++i) {
        for (int nb = 0; nb < this->_fileContent.size(); nb++) {
                this->_fileContent[nb] = saveFileContent[nb] ^ i;
        }
        if (this->unCiphered() != -1) {
            std::cout << "KEY = " << (char)i << " (" << i << ")" << std::endl;
            this->_data->setFileContent(this->_fileContent);
            this->_data->Execute();
            return (0);
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
                this->_data->setFileContent(this->_fileContent);
                this->_data->Execute();
                return (0);
            }
        }
    }
    return (0);
}