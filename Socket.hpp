#ifndef SOCKET_HPP_
# define SOCKET_HPP_

#include "ASocket.hpp"

namespace Plazza {
	namespace Controller {
		class Socket : Plazza::Controller::ASocket {
		private:
			unsigned int _port;
			int InitSocketParent();
			int InitSocketChild();
		public:
			Socket();
			virtual ~Socket() {};
		};
	}
}

#endif