#ifndef IMODEL_HPP_
# define IMODEL_HPP_

#include <iostream>
#include "IObserver.hpp"

namespace Plazza {
	namespace Model {
		class IModel {
		private:
			virtual void Reset() = 0;
			virtual void AddObserver(Plazza::IObserver *observer) = 0;
			virtual void NotifyObserver(std::string data) = 0;
			virtual void RemoveObservers() = 0;
			virtual void RemoveObserver(Plazza::IObserver *observer) = 0;
			virtual void GetData() = 0;
		public:
			virtual ~IModel() {};
		};
	}
}

#endif
