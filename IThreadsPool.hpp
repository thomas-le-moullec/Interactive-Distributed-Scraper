#ifndef ITHREADSPOOL_HPP_
# define ITHREADSPOOL_HPP_

#include <iostream>
#include "Order.hpp"
#include "IThread.hpp"
#include "IMutex.hpp"

namespace Plazza {
	namespace Controller {
		class IThreadsPool {
		private:
			virtual Order popOrder() = 0;
			virtual void 	pushOrder(Order order) = 0;
			virtual int 	getCurrentOrder() = 0;
		public:
			virtual ~IThreadsPool() {};
		};
	}
}

#endif
