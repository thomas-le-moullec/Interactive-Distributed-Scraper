#ifndef MUTEX_HPP_
#define MUTEX_HPP_

#include "IMutex.hpp"

namespace Plazza {
  class	Mutex : public IMutex
  {
  public:
    Mutex();
    virtual ~Mutex();
    virtual void 								lock();
    virtual void 								unlock();
    virtual void 								trylock();
    virtual	pthread_mutex_t			*getMutex();
  private:
    pthread_mutex_t		_mutex;
  };
}

#endif
