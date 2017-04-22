#ifndef IPROCESS_HPP_
# define IPROCESS_HPP_

#include <iostream>
<<<<<<< HEAD
#include "Order.hpp"
#include "IStrategyData.hpp"
=======
#include "IStrategyInformation.hpp"
>>>>>>> c67d3a2e8417864314f0a06522002ea150bf7498

namespace Plazza {
	namespace Controller {

<<<<<<< HEAD
=======
		struct Order {
			IStrategyInformation *_strategy;
			std::string _file;
		};

>>>>>>> c67d3a2e8417864314f0a06522002ea150bf7498
		class IProcess {
		private:
			virtual Plazza::Controller::Order parseOrder(std::string order) = 0;
		public:
			virtual ~IProcess() {};
		};
	}
}

#endif
