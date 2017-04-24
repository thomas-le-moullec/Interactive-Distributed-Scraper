#ifndef IPROCESSMANAGER_HPP_
#define IPROCESSMANAGER_HPP_

#include <iostream>
#include "Socket.hpp"

namespace Plazza {
	namespace Controller {
		class IProcessManager {
		public:
			virtual ~IProcessManager() {};
			virtual void addProcess(unsigned int, Socket *) = 0; // A OVERLOAD
			virtual void NotifyController(char) = 0;
			virtual int getStatus() = 0;
			virtual int getPid() = 0;
		};
	}
}

#endif
