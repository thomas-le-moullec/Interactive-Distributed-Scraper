#ifndef APROCESS_HPP_
# define APROCESS_HPP_

#include "IProcess.hpp"
#include "IThreadsPool.hpp"
#include "IModel.hpp"

namespace Plazza {
	namespace Controller {

		class AProcess : public IProcess {
		public:
			virtual ~AProcess() {};
			virtual void 											control() = 0;
			virtual Order 										parseOrder(std::string) = 0;

		protected:
			AProcess();
			IThreadsPool											*_tp;
			//Plazza::Model::IModel	 						*_model;
			Order															_order;
			std::string												_message;
		};
	}
}

#endif
