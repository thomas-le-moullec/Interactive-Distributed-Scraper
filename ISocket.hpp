#ifndef ISOCKET_HPP_
# define ISOCKET_HPP_

#include "ICommunication.hpp"

namespace Plazza {
	namespace Controller {
		class ISocket : public ICommunication {
		private:
		public:
			virtual ~ISocket() {};
		};
	}
}

#endif
