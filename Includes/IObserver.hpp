#ifndef IOBSERVER_HPP_
# define IOBSERVER_HPP_

#include <iostream>
#include <vector>

namespace Plazza {
	class IObserver {
	public:
		virtual ~IObserver() {};
		virtual void Update(std::vector<std::string> data) = 0;
	};
}

#endif
