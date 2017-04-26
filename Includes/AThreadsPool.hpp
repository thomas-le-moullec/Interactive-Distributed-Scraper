#ifndef ATHREADSPOOL_HPP_
# define ATHREADSPOOL_HPP_

#include <vector>
#include "IThreadsPool.hpp"
#include "IStrategyCipher.hpp"
//#include "AProcess.hpp"
#include "IModel.hpp"

namespace Plazza {
	namespace Controller {
		class AThreadsPool : public IThreadsPool
		{
		public:
			virtual Order popOrder() = 0;
			virtual void 	pushOrder(Order order) = 0;
			virtual int 	getCurrentOrder() = 0;
			virtual void 	execOrder() = 0;
			virtual ~AThreadsPool() {};

		protected:
			AThreadsPool();
		};
	}
}

#endif
