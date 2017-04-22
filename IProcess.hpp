#ifndef IPROCESS_HPP_
# define IPROCESS_HPP_

#include <iostream>
#include "IStrategyInformation.hpp"

namespace Plazza {
	namespace Controller {

		struct Order {
			IStrategyInformation *_strategy;
			std::string _file;
		};

		class IProcess {
		private:
			virtual std::string takeOrderFromSockets() = 0;
			virtual Plazza::Controller::Order parseOrder(std::string order) = 0;
		public:
			virtual ~IProcess() {};
		};
	}
}

#endif
