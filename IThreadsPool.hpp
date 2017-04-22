#ifndef ITHREADSPOOL_HPP_
# define ITHREADSPOOL_HPP_

#include <iostream>
#include "IThread.hpp"
#include "IMutex.hpp"

namespace Plazza {
	namespace Controller {
		class IThreadsPool {
		private:
			virtual void PopOrder(std::string order) = 0;
			virtual void PushOrder(std::string order) = 0;
			virtual void AssignOrderToThread(std::string order, Plazza::IThread *myThread) = 0;
			virtual unsigned int GetFreeSlots() = 0;
		public:
			virtual ~IThreadsPool() {};
		};
	}
}

#endif