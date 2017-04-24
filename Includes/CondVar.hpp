#ifndef CONDVAR_HPP_
#define	CONDVAR_HPP_

#include "Mutex.hpp"

namespace Plazza {
  class	CondVar
  {
  public:
    CondVar();
    ~CondVar();
    void	signal();
    void	wait(IMutex *);
  private:
    pthread_cond_t	_cond;
  };
}

#endif
