#ifndef ASOCKET_HPP_
# define ASOCKET_HPP_

#include "ISocket.hpp"

namespace Plazza {
	namespace Controller {
		class ASocket : public ISocket {
		private:
			unsigned int _port;
		public:
			virtual ~ASocket() {};
		protected:
			ASocket();
		};
	}
}

#endif
