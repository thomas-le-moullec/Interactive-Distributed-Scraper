#ifndef IPROCESS_HPP_
# define IPROCESS_HPP_

#include <iostream>
#include "Order.hpp"
#include "IStrategyInformation.hpp"

namespace Plazza {
	namespace Controller {
		class IProcess {
		public:
			virtual ~IProcess() {};
			virtual void 											control() = 0;
			virtual Order 										parseOrder(std::string) = 0;
		};
	}
}

#endif
