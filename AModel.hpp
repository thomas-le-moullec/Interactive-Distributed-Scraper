#ifndef 	AMODEL_HPP_
# define 	AMODEL_HPP_

#include "IObservable.hpp"
#include "IModel.hpp"
#include <vector>

namespace Plazza {
	namespace Model {
		class AModel : Plazza::Model::IModel, Plazza::IObservable {
		private:
			std::string data;
            std::vector<Plazza::IObserver *> listObservers;
			virtual void Reset() = 0;
			virtual void AddObserver(Plazza::IObserver *observer);
			virtual void NotifyObserver(std::string data);
			virtual void RemoveObservers();
			virtual void RemoveObserver(Plazza::IObserver *observer);
			virtual void GetData() = 0;

		public:
			virtual ~AModel() {};

		protected:
			AModel();
		};
	}
}

#endif
