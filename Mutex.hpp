#ifndef MUTEX_HPP_
# define MUTEX_HPP_

#include "IMutex.hpp"

namespace Plazza {
	class Mutex : Plazza::IMutex {
	private:
		pthread_mutex_t _mutex;
		void lock();
		void unlock();
		void trylock();
	};
}

#endif