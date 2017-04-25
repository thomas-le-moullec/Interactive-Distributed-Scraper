#ifndef 	AMODEL_HPP_
# define 	AMODEL_HPP_

#include "IObservable.hpp"
#include "IModel.hpp"
#include <vector>

namespace Plazza {
	namespace Model {
		class AModel : public IModel, public IObservable {
		private:
			std::string data;
      std::vector<Plazza::IObserver *> listObservers;
        public:
			virtual void Reset() = 0;
			virtual void AddObserver(Plazza::IObserver *observer);
			virtual void NotifyObserver(std::string data);
			virtual void RemoveObservers();
			virtual void RemoveObserver(Plazza::IObserver *observer);
			virtual void GetData(std::vector<std::string>) = 0;
			virtual ~AModel() {};

		protected:
			AModel();
		};
	}
}

#endif
