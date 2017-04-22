#ifndef IPROCESS_HPP_
# define IPROCESS_HPP_

#include <iostream>
#include "Order.hpp"
#include "IStrategyData.hpp"

namespace Plazza {
	namespace Controller {

		class IProcess {
		private:
			virtual Plazza::Controller::Order parseOrder(std::string order) = 0;
		public:
			virtual ~IProcess() {};
		};
	}
}

#endif
