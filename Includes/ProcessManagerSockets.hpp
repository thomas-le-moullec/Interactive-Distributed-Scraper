#ifndef PROCESSMANAGERSOCKETS_HPP_
#define	PROCESSMANAGERSOCKETS_HPP_

#include <unistd.h>
#include <fstream>
#include <utility>
#include <string>
#include <map>

#include "AProcessManager.hpp"
#include "Process.hpp"
#include "AController.hpp"
#include "Socket.hpp"
#include "IStrategyCipher.hpp"
#include "Xor.hpp"
#include "Caesar.hpp"
#include "Order.hpp"
#include "OpaqueType.hpp"

namespace Plazza {
  namespace Controller {
    class		ProcessManagerSockets : public AProcessManager, public AController
    {
    public:
      ProcessManagerSockets(unsigned int);
      ~ProcessManagerSockets();
      void											addProcess(unsigned int, ISocket *);
      void											control(unsigned int);
      int 											getStatus();
      int 											getPid();
      void 											NotifyController(char);
      std::vector<std::string> 	ParseCommandLine(std::string order);
      orderBySocket							fromBufferToStruct(std::string str);
    private:
      std::vector<Plazza::IStrategyCipher *> 	_ciphers;
      std::vector<int>												_fdProcess;
      std::pair<int, int>											_processToFeed;
      std::map<std::string, Information>	 		_strEnum;
      std::string 														_commandLine;
      std::string															_message;
      ISocket																	*_socket;
      int																			_nbThreadsBusy;
      unsigned int														_numPort;
    };
  }
}

#endif
