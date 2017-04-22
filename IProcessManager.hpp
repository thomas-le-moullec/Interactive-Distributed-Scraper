#ifndef IPROCESSMANAGER_HPP_
# define IPROCESSMANAGER_HPP_

#include <iostream>
#include "Socket.hpp"

namespace Plazza {
	namespace Controller {
		class IProcessManager {
		private:
			virtual void addProcess(unsigned int, Socket *) = 0;
			virtual int getStatus() = 0;
			virtual int getPid() = 0;

		public:
			virtual ~IProcessManager() {};
		};
	}
}

#endif
