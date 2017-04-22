#ifndef THREADSPOOL_HPP_
# define THREADSPOOL_HPP_

#include "AThreadsPool.hpp"

namespace Plazza {
	namespace Controller {
		class ThreadsPool : Plazza::Controller::AThreadsPool {
		private:
			std::vector<Plazza::Controller::Order *> _order;
			std::vector<IThread *> _threadPool;
			std::vector<IStrategyCipher *> _cipherStrats;
			Plazza::Model::IModel *_model;
			Plazza::IMutex *_mutex;
			unsigned int _nbThread;
			void execOrder();
			void PopOrder();
			void PushOrder(Plazza::Controller::Order order);
			unsigned int GetFreeslots();

		public:
			ThreadsPool();
			virtual ~ThreadsPool() {};
		};
	}
}

#endif