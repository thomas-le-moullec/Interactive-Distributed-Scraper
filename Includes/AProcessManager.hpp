#ifndef APROCESSMANAGER_HPP_
#define APROCESSMANAGER_HPP_

#include "IProcessManager.hpp"

namespace Plazza {
	namespace Controller {
		class AProcessManager : public IProcessManager {
		protected:
			AProcessManager();
		public:
			virtual ~AProcessManager() {};
			virtual void 								addProcess(unsigned int, ISocket *) = 0;
			virtual std::vector<int> 		getStatus() = 0;
			virtual int 								getPid() = 0;
		};
	}
}

#endif
