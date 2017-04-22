#ifndef ITHREAD_HPP_
# define ITHREAD_HPP_

#include <thread>
#include <iostream>

namespace Plazza {
	class IThread {
	private:
		//virtual void create(const thread_attr_t* myThread, void*(* start)(void *), void* args) = 0;
		virtual void join() = 0;
		virtual bool joinable() = 0;

	public:
		virtual ~IThread() {};
	};
}

#endif