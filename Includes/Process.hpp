#ifndef	PROCESS_HPP_
#define	PROCESS_HPP_

#include <iostream>
#include <unistd.h>
#include "Socket.hpp"
#include "ThreadPool.hpp"
#include "Order.hpp"
#include "AProcess.hpp"

#include "OpaqueType.hpp"
#include "ContextInformation.hpp"
#include "StrategyIpAddress.hpp"
#include "StrategyPhoneNumber.hpp"
#include "StrategyEmailAddress.hpp"

namespace Plazza {
  namespace Controller {
    class		Process : public AProcess
    {
    public:
      Process(unsigned int, ISocket *, Plazza::Model::IModel *);
      ~Process();
      Order						parseOrder(std::string);
      void						control();
    private:
      ISocket																	*_socket;
      int																			_fdSocket;
      Plazza::Model::IModel 									*_model;
    };
  }
}
#endif
