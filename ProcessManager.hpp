#ifndef PROCESSMANAGER_HPP_
#define	PROCESSMANAGER_HPP_

#include <unistd.h>
#include <fstream>
#include <utility>

#include "AProcessManager.hpp"
#include "Process.hpp"
#include "Socket.hpp"

namespace Plazza {
  namespace Controller {
    class		ProcessManager : public AProcessManager
    {
    public:
      ProcessManager(unsigned int);
      ~ProcessManager();
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
