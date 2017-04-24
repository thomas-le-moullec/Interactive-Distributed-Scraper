#ifndef THREAD_HPP_
# define THREAD_HPP_

#include "IThread.hpp"

namespace Plazza {
	class Thread : public IThread {
	private:
		pthread_t _thread;
		//void create(const thread_attr_t* myThread, void*(* start)(void *), void* args);
		void join();
		bool joinable();

	public:
		Thread();
		virtual ~Thread(){};
	};
}

#endif
