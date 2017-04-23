//
// Created by tchikl_h on 4/18/17.
//

#include "Caesar.h"

Caesar::Caesar(IData *data, std::string const &fileName) : ACipher(data, fileName)
{
}

int             Caesar::Cipher()
{
    for (int i = 0; i < 255; ++i) {
        if (this->unCiphered() != -1) {
            std::cout << "KEY = " << (char)i << " (" << i << ")" << std::endl;
            this->_data->setFileContent(this->_fileContent);
            this->_data->Execute();
            return (0);
        }
        for (int j = 0; j < this->_fileContent.size(); j++) {
            this->_fileContent[j]++;
        }
    }
    return (0);
}