#ifndef PROCESSMANAGERSOCKETS_HPP_
#define	PROCESSMANAGERSOCKETS_HPP_

#include <unistd.h>
#include <fstream>
#include <utility>

#include "AProcessManager.hpp"
#include "Process.hpp"
#include "AController.hpp"
#include "Socket.hpp"

namespace Plazza {
  namespace Controller {
    class		ProcessManagerSockets : public AProcessManager, public AController
    {
    public:
      ProcessManagerSockets(unsigned int);
      ~ProcessManagerSockets();
      void										addProcess(unsigned int, ISocket *);
      void										control(unsigned int);
      int 										getStatus();
      int 										getPid();
      void 										NotifyController(char);
      std::vector<std::string> ParseCommandLine(std::string order);
    private:
      ISocket									*_socket;
      std::vector<int>				_fdProcess;
      std::string							_message;
      std::pair<int, int>			_processToFeed;
      int											_nbThreadsBusy;
      unsigned int						_numPort;

      std::string 					_commandLine;
    };
  }
}

#endif
