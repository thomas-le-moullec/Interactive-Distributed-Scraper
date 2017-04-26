#ifndef PROCESSMANAGERSOCKETS_HPP_
#define	PROCESSMANAGERSOCKETS_HPP_

#include <unistd.h>
#include <fstream>
#include <utility>
#include <string>
#include <map>
#include <signal.h>

#include "AProcessManager.hpp"
#include "Process.hpp"
#include "AController.hpp"
#include "Socket.hpp"
#include "Order.hpp"
#include "OpaqueType.hpp"

namespace Plazza {
  namespace Controller {
    class		ProcessManagerSockets : public AProcessManager, public AController
    {
    public:
      ProcessManagerSockets(unsigned int, Plazza::Model::IModel *);
      ~ProcessManagerSockets();
        void sendMessage(std::string, int) const;
        std::string receiveMessage(int) const;
      void											addProcess(unsigned int, ISocket *);
      //void 											my_handler(int);
      void											control();
      std::vector<int>					getStatus();
      int 											getPid();
      void 											NotifyController(char);
      std::vector<std::string> 	ParseCommandLine(std::string order);
      orderBySocket							fromBufferToStruct(std::string str);
    private:
      unsigned int														_numPort;
      unsigned int														_nbThreads;
      std::vector<int>												_fdProcess;
      std::pair<int, int>											_processToFeed;
      std::map<std::string, Information>	 		_strEnum;
      std::string 														_commandLine;
      std::string															_message;
      int																			_nbThreadsBusy;
    };
  }
}

#endif
