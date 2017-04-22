#include "CondVar.hpp"

Plazza::CondVar::CondVar()
{
  pthread_cond_init(&_cond, NULL);
}

Plazza::CondVar::~CondVar()
{
  pthread_cond_destroy(&_cond);
}

void	Plazza::CondVar::signal()
{
  pthread_cond_signal(&_cond);
}

void	Plazza::CondVar::wait(Mutex &mutex)
{
  pthread_cond_wait(&_cond, mutex.getMutex());
}
