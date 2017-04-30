#ifndef ITHREAD_HPP_
# define ITHREAD_HPP_

#include <iostream>

namespace Plazza {
	class IThread {
	public:
		virtual void join(void **) = 0;
		virtual ~IThread() {};
	};
}

#endif
