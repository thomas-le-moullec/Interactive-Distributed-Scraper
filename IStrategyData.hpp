#ifndef ISTRATEGYDATA_HPP_
# define ISTRATEGYDATA_HPP_

#include <iostream>

namespace Plazza {
	class IStrategyData {
	private:
		virtual void execute(std::string dataPattern) = 0;

	public:
		virtual ~IStrategyData() {};
	};
}

#endif