#ifndef ORDER_HPP_
#define ORDER_HPP_

#include <iostream>
#include "IStrategyData.hpp"

namespace Plazza {
	namespace Controller {

		struct Order {
			IStrategyData *_strategy;
			std::string _file;
		};
  }
}

#endif
