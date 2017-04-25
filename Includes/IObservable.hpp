#ifndef IOBSERVABLE_HPP_
# define IOBSERVABLE_HPP_

#include "IObserver.hpp"

namespace Plazza {
	class IObservable {
	private:
		virtual void AddObserver(Plazza::IObserver *observer) = 0;
		virtual void NotifyObserver(std::vector<std::string> data) = 0;
		virtual void RemoveObservers() = 0;
		virtual void RemoveObserver(Plazza::IObserver *observer) = 0;

	public:
		virtual ~IObservable() {};
	};
}

#endif
