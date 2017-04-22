#ifndef 	DATA_HPP_
# define 	DATA_HPP

#include "AModel.hpp"

namespace Plazza {
	namespace Model {
		class Data : Plazza::Model::AModel {
		private:
			std::string data;
			std::vector<Plazza::IObserver *> listObservers;
			void Reset();
			void AddObserver(Plazza::IObserver *observer);
			void NotifyObserver(std::string data);
			void RemoveObservers();
			void RemoveObserver(Plazza::IObserver *observer);
			void GetData();
		public:
			Data();
			virtual ~Data() {};
		};
	}
}

#endif
