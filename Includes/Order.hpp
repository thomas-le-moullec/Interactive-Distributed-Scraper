#ifndef ORDER_HPP_
#define ORDER_HPP_

#include <iostream>
#include "IStrategyInformation.hpp"

namespace Plazza {
	namespace Controller {

		struct Order {
			IStrategyInformation *_strategy;
			std::string _file;
		};
  }
}

#endif
