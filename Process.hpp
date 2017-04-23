#ifndef	PROCESS_HPP_
#define	PROCESS_HPP_

#include <iostream>
#include <unistd.h>
#include "Socket.hpp"
#include "ThreadPool.hpp"
#include "Order.hpp"

namespace Plazza {
  namespace Controller {
    class		Process : public AProcess
    {
    public:
      Process(unsigned int, Socket *);
      ~Process();
      Order						parseOrder(std::string);
      void						control();
    private:
      IThreadsPool		*_tp;
      Socket					*_socket;
      int							_fdSocket;
      std::string			_message;
      Order						_order;
      time_t					_time; // A ENCAPSULER
    };
  }
}
#endif
