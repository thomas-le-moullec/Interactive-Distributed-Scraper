#ifndef APROCESS_HPP_
# define APROCESS_HPP_

#include "IProcess.hpp"
#include "IThreadsPool.hpp"

namespace Plazza {
	namespace Controller {

		class AProcess : public IProcess {
		private:
			Plazza::Controller::IThreadsPool *_threadsPool;
			std::string _order;
			int _fdSocket;
			virtual Plazza::Controller::Order parseOrder(std::string order) = 0;
			virtual void control() = 0;

		public:
			virtual ~AProcess() {};

		protected:
			AProcess();
		};
	}
}

#endif
