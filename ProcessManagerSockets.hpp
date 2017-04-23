#ifndef PROCESSMANAGERSOCKETS_HPP_
#define	PROCESSMANAGERSOCKETS_HPP_

#include <unistd.h>
#include <fstream>
#include <utility>

#include "AProcessManager.hpp"
#include "Process.hpp"
#include "Socket.hpp"

namespace Plazza {
  namespace Controller {
    class		ProcessManagerSockets : public AProcessManager
    {
    public:
      ProcessManagerSockets(unsigned int);
      ~ProcessManagerSockets();
      void										addProcess(unsigned int, Socket *);
      void										control(unsigned int);
      int 										getStatus();
      int 										getPid();
    private:
      Socket									*_socket;
      std::vector<int>				_fdProcess;
      std::string							_message;
      std::pair<int, int>			_processToFeed;
      int											_nbThreadsBusy;
      unsigned int						_numPort;
    };
  }
}

#endif
