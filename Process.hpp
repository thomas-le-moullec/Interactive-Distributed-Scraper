#ifndef PROCESS_HPP_
# define PROCESS_HPP

#include "AProcess.hpp"

namespace Plazza {
	namespace Controller {
		class Process : Plazza::Controller::AProcess {
		private:
			Plazza::Controller::IThreadsPool *_threadsPool;
			std::string _order;
			int _fdSocket;
			std::string takeOrderFromSockets();
			Plazza::Controller::Order parseOrder(std::string order);
			void control();
		public:
			virtual ~Process() {};
			Process();
		};
	}
}

#endif