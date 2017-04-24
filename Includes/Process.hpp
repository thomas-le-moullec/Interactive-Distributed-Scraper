#ifndef	PROCESS_HPP_
#define	PROCESS_HPP_

#include <iostream>
#include <unistd.h>
#include "Socket.hpp"
#include "ThreadPool.hpp"
#include "Order.hpp"
#include "AProcess.hpp"
#include "ContextInformation.hpp"
#include "StrategyIpAddress.hpp"
#include "StrategyPhoneNumber.hpp"
#include "StrategyEmailAddress.hpp"

namespace Plazza {
  namespace Controller {
    class		Process : public AProcess
    {
    public:
      Process(unsigned int, ISocket *, Plazza::Model::IModel *, std::vector<Plazza::IStrategyCipher *>&);
      ~Process();
      Order						parseOrder(std::string);
      void						control();
    private:
      IThreadsPool		*_tp;
      ISocket					*_socket;
      int							_fdSocket;
      std::string			_message;
      Order						_order;
      time_t					_time; // A ENCAPSULER
        std::vector<Plazza::IStrategyCipher *> _ciphers;
        Plazza::Model::IModel *_model;
    };
  }
}
#endif