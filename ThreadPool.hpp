#ifndef THREADPOOL_HPP_
#define	THREADPOOL_HPP_

#include <vector>
#include <iostream>
#include <pthread.h>
#include <unistd.h>

//#include "IStrategyData.hpp"
#include "AThreadsPool.hpp"
#include "Time.hpp"
#include "Thread.hpp"
#include "Mutex.hpp"
#include "CondVar.hpp"
#include "Order.hpp"

namespace Plazza {
  namespace Controller {
    class		ThreadPool : public AThreadsPool
    {
    public:
      ThreadPool(unsigned int);
      ~ThreadPool();
      void									pushOrder(Order);
      void									execOrder();
      int										getCurrentOrder();
      Order									popOrder();

    private:
      std::vector<Order> 						_orders;
      std::vector<std::thread *>		_threads;
      IMutex												*_mutex; // A CHANGER EN MUTEX SI PROBLEME
      CondVar												_cond;
      unsigned int									_nbThreads;
      unsigned int									_ordersExecuted;
      Time													_time;
      Time													_now;
    };
  }
}

#endif
