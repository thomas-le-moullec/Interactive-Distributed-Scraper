#ifndef THREADPOOL_HPP_
#define	THREADPOOL_HPP_

#include <vector>
#include <iostream>
//#include <pthread.h>
#include <unistd.h>

#include "Xor.hpp"
#include "Atbash.hpp"
#include "Caesar.hpp"
#include "Thread.hpp"
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
      ThreadPool(unsigned int, Plazza::Model::IModel *);
      ~ThreadPool();
      void									pushOrder(Order);
      int										getCurrentOrder();
      void									execOrder();
      Order									popOrder();

    private:
      std::vector<Order> 						_orders;
      std::vector<Thread *>					_threads;

      IMutex												*_mutex;
      CondVar												_cond;
      unsigned int									_nbThreads;
      unsigned int									_ordersExecuted;
      Time													_time;
      Time													_now;
      Plazza::Model::IModel 				*_model;
    };
    void									*execOrder(void *);
  }
}

#endif
