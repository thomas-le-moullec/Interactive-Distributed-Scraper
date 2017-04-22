#ifndef APROCESSMANAGER_HPP_
# define APROCESSMANAGER_HPP_

#include "IProcessManager.hpp"
#include <vector>

namespace Plazza {
	namespace Controller {
		class AProcessManager : Plazza::Controller::IProcessManager {
		private:
			std::vector<int> _idProcess;
			virtual void addProcess() = 0;
			virtual int getStatus() = 0;
			virtual int getPid() = 0;
		protected:
			AProcessManager();
		public:
			virtual ~AProcessManager() {};
		};
	}
}

#endif