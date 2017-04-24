#ifndef IMUTEX_HPP_
# define IMUTEX_HPP_

#include <pthread.h>

namespace Plazza {
	class IMutex {
	public:
		virtual void 								lock() = 0;
		virtual void 								unlock() = 0;
		virtual void 								trylock() = 0;
		virtual	pthread_mutex_t			*getMutex() = 0;
	};
}

#endif
