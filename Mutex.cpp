#include "Mutex.hpp"

Plazza::Mutex::Mutex()
{
  pthread_mutex_init(&_mutex, NULL);
}

Plazza::Mutex::~Mutex()
{
  pthread_mutex_destroy(&_mutex);
}

void 			Plazza::Mutex::lock()
{
  pthread_mutex_lock(&_mutex);
}

void 			Plazza::Mutex::unlock()
{
  pthread_mutex_unlock(&_mutex);
}

void 			Plazza::Mutex::trylock()
{
  pthread_mutex_trylock(&_mutex);
}

pthread_mutex_t			*Plazza::Mutex::getMutex()
{
  return &_mutex;
}
