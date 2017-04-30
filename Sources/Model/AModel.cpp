#include "AModel.hpp"

void Plazza::Model::AModel::AddObserver(Plazza::IObserver *observer) {
    _listObservers.insert(_listObservers.end(), observer);
}

void Plazza::Model::AModel::NotifyObserver(std::vector<std::string> data) {
	for (unsigned int i = 0; i < _listObservers.size(); i++) {
        _listObservers[i]->Update(data);
    }
}

void Plazza::Model::AModel::RemoveObservers() {
	delete &_listObservers;
}

void Plazza::Model::AModel::RemoveObserver(Plazza::IObserver *observer) {
  (void)observer;
	for (unsigned int i = 0; i < _listObservers.size(); i++) {
        /*if (_listObservers[i] == observer) {
            _listObservers.erase(observer);
        }*/
    }
}

Plazza::Model::AModel::AModel() {
}
