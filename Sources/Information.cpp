#include "Information.hpp"

void Plazza::Model::Information::Reset() {
	_informations.clear();
}

void Plazza::Model::Information::GetData(std::vector<std::string> informations) {
	_informations.insert(_informations.end(), informations);
	NotifyObserver(informations);
}

void Plazza::Model::Information::SaveData(std::string fileName) {
    std::ofstream outputFile;

    outputFile.open(fileName.c_str());
    for (unsigned int i = 0; _informations.size(); i++) {
        for (unsigned int j = 0; _informations.size(); j++) {
            outputFile << _informations[i][j];
        }
    }
    outputFile.close();
}

Plazza::Model::Information::Information() {
}
