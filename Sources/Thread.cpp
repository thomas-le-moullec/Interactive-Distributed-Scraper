#include "Thread.hpp"

Plazza::Thread::Thread(const pthread_attr_t *attr, void *(*start)(void *), void *arg) {
	pthread_create(&_thread, attr, start, arg);
}

void Plazza::Thread::join(void **value) {
	  pthread_join(_thread, value);
}

/*bool Plazza::Thread::joinable() {

}*/
