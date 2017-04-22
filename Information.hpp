#ifndef 	INFORMATION_HPP
# define 	INFORMATION_HPP

#include "AModel.hpp"

namespace Plazza {
	namespace Model {
		class Information : Plazza::Model::AModel {
		private:
			std::string _information;
			std::vector<Plazza::IObserver *> listObservers;
			void Reset();
			void AddObserver(Plazza::IObserver *observer);
			void NotifyObserver(std::string Information);
			void RemoveObservers();
			void RemoveObserver(Plazza::IObserver *observer);
			void GetData();
		public:
			Information();
			virtual ~Information() {};
		};
	}
}

#endif
