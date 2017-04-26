#include "Information.hpp"

void Plazza::Model::Information::Reset() {
	_informations.clear();
}

void Plazza::Model::Information::GetData(std::vector<std::string> informations) {
	_informations.insert(_informations.end(), informations);
	NotifyObserver(informations);
}

void Plazza::Model::Information::SaveData(std::string fileName) {
    static bool saved = false;
    std::ofstream outputFile;
    std::cout << "SAVE DATA IN :" << fileName << std::endl;
    if (saved == false) {
        outputFile.open(fileName.c_str());
        for (unsigned int i = 0; i < _informations.size(); i++) {
            for (unsigned int j = 0; j < _informations[i].size(); j++) {
                outputFile << _informations[i][j] << std::endl;
            }
        }
        outputFile.close();
        if (_informations.size() > 0) {
            saved = true;
        }
    }
}

Plazza::Model::Information::Information() {
}
