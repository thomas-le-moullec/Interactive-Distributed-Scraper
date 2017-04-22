#ifndef ISOCKET_HPP_
# define ISOCKET_HPP_

#include "ICommunication.hpp"

namespace Plazza {
	namespace Controller {
		class ISocket : Plazza::Controller::ICommunication {
		private:
			virtual int InitSocketParent() = 0;
			virtual int InitSocketChild() = 0;
		public:
			virtual ~ISocket() {};
		};
	}
}

#endif