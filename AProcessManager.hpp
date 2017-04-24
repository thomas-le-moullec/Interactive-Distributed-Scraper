#ifndef APROCESSMANAGER_HPP_
#define APROCESSMANAGER_HPP_

#include "IProcessManager.hpp"
#include <vector>

namespace Plazza {
	namespace Controller {
		class AProcessManager : public IProcessManager {
		protected:
			//std::vector<int> _idProcess;
			AProcessManager();
		public:
			virtual ~AProcessManager() {};
			virtual void NotifyController(char input) = 0;
			virtual void addProcess(unsigned int, Socket *) = 0;
			virtual int getStatus() = 0;
			virtual int getPid() = 0;
		};
	}
}

#endif
