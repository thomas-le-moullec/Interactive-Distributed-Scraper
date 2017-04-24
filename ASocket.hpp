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
			virtual int                 socketChild() = 0;
			virtual int                 socketParent() = 0;
			virtual void            		sendMessage(std::string, int) const = 0;
			virtual std::string    			receiveMessage(int) const = 0;
			virtual int                 getPort() const = 0;
		protected:
			ASocket();
		};
	}
}

#endif
