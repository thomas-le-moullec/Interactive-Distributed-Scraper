#ifndef IOBSERVER_HPP_
# define IOBSERVER_HPP_

#include <iostream>

namespace Plazza {
	class IObserver {
	private:
		virtual void Update(std::string data) = 0;

	public:
		virtual ~IObserver() {};
	};
}

#endif
