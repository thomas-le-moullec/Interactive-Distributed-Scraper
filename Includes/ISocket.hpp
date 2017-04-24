#ifndef ISOCKET_HPP_
# define ISOCKET_HPP_

#include "ICommunication.hpp"

namespace Plazza {
	namespace Controller {
		class ISocket : public ICommunication {
		public:
			virtual ~ISocket() {};
			virtual int                 socketChild() = 0;
			virtual int                 socketParent() = 0;
			virtual void            		sendMessage(std::string, int) const = 0;
			virtual std::string    			receiveMessage(int) const = 0;
			virtual int                 getPort() const = 0;
		};
	}
}

#endif
