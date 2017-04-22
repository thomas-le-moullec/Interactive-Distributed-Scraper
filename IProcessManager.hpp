#ifndef IPROCESSMANAGER_HPP_
# define IPROCESSMANAGER_HPP_

#include <iostream>

namespace Plazza {
	namespace Controller {
		class IProcessManager {
		private:
			virtual void addProcess() = 0;
			virtual int getStatus() = 0;
			virtual int getPid() = 0;

		public:
			virtual ~IProcessManager() {};
		};
	}
}

#endif
