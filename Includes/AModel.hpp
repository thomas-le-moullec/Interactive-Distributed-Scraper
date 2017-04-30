#ifndef 	AMODEL_HPP_
# define 	AMODEL_HPP_

#include "IObservable.hpp"
#include "IModel.hpp"
#include <fstream>

namespace Plazza {
	namespace Model {
		class AModel : public IModel, public IObservable {
    public:
			virtual void Reset() = 0;
			virtual void AddObserver(Plazza::IObserver *observer);
			virtual void NotifyObserver(std::vector<std::string> data);
			virtual void RemoveObservers();
			virtual void RemoveObserver(Plazza::IObserver *observer);
			virtual void GetData(std::vector<std::string>) = 0;
			virtual void SaveData(std::string) = 0;
			virtual ~AModel() {};

		protected:
			AModel();
			static const std::string                            LOGS_PATH;
			std::vector<Plazza::IObserver *> 										_listObservers;
		};
	}
}

#endif
