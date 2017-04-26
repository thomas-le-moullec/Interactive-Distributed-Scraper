#include "AModel.hpp"

void Plazza::Model::AModel::AddObserver(Plazza::IObserver *observer) {
    std::cout << "Size Observ before --> " << _listObservers.size() << std::endl;
    _listObservers.insert(_listObservers.end(), observer);
    std::cout << "Size Observ aftrer --> " << _listObservers.size() << std::endl;

}

void Plazza::Model::AModel::NotifyObserver(std::vector<std::string> data) {
    std::cout << "List Observers" << _listObservers.size() << std::endl;
	for (int i = 0; i < _listObservers.size(); i++) {
        _listObservers[i]->Update(data);
    }
}

void Plazza::Model::AModel::RemoveObservers() {
	delete &_listObservers;
    //new
}

void Plazza::Model::AModel::RemoveObserver(Plazza::IObserver *observer) {
	for (int i = 0; i < _listObservers.size(); i++) {
        /*if (_listObservers[i] == observer) {
            _listObservers.erase(observer);
        }*/
    }
}

Plazza::Model::AModel::AModel() {
	std::cout << "AModel builded !" << std::endl;
}
