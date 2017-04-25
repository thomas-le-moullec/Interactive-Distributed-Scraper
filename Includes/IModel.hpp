#ifndef IMODEL_HPP_
# define IMODEL_HPP_

#include <iostream>
#include <vector>
#include "IObserver.hpp"

namespace Plazza {
	namespace Model {
		class IModel {
        public:
			virtual void Reset() = 0;
			virtual void AddObserver(Plazza::IObserver *observer) = 0;
			virtual void NotifyObserver(std::string data) = 0;
			virtual void RemoveObservers() = 0;
			virtual void RemoveObserver(Plazza::IObserver *observer) = 0;
			virtual void GetData(std::vector<std::string>) = 0;
			virtual ~IModel() {};
		};
	}
}

#endif
