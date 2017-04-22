#ifndef ATHREADSPOOL_HPP_
# define ATHREADSPOOL_HPP_

#include <vector>
#include "IThreadsPool.hpp"
#include "IStrategyCipher.hpp"
#include "AProcess.hpp"
#include "IModel.hpp"

namespace Plazza {
	namespace Controller {
		class AThreadsPool : Plazza::Controller::IThreadsPool {
		private:
			std::vector<Plazza::Controller::Order *> _order;
			std::vector<IThread *> _threadPool;
			std::vector<IStrategyCipher *> _cipherStrats;
			Plazza::Model::IModel *_model;
			Plazza::IMutex *_mutex;
			unsigned int _nbThread;

			virtual void PopOrder() = 0;
			virtual void PushOrder(Plazza::Controller::Order order) = 0;
			virtual unsigned int GetFreeslots() = 0;
			virtual void execOrder() = 0;
		public:
			virtual ~AThreadsPool() {};

		protected:
			AThreadsPool();
		};
	}
}

#endif