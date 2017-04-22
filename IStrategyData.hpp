#ifndef ISTRATEGYDATA_HPP_
# define ISTRATEGYDATA_HPP_

#include <iostream>

namespace Plazza {
	class IStrategyData {
	public:
		virtual ~IStrategyData() {};
		virtual void execute(std::string dataPattern) = 0;
	};
}

#endif
