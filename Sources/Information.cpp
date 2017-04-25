#include "Information.hpp"

void Plazza::Model::Information::Reset() {
	_informations.clear();
}

void Plazza::Model::Information::GetData(std::vector<std::string> informations) {
	_informations.insert(_informations.end(), informations);
	NotifyObserver(informations);
}

Plazza::Model::Information::Information() {
}
