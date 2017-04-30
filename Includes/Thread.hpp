#ifndef THREAD_HPP_
# define THREAD_HPP_

#include <pthread.h>
#include "IThread.hpp"

namespace Plazza {
	class Thread : public IThread {
	private:
		pthread_t _thread;

	public:
		Thread(const pthread_attr_t *attr, void *(*start)(void *), void *arg);
		virtual ~Thread(){};
		virtual void join(void **value);
	};
}

#endif
