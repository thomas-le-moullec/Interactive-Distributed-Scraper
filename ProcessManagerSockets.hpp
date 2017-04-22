#ifndef PROCESSMANAGERSOCKETS_HPP_
# define PROCESSMANAGERSOCKETS_HPP_

#include "AController.hpp"
#include "AProcessManager.hpp"
#include "ASocket.hpp"

namespace Plazza {
	namespace Controller {
		class ProcessManagerSockets : Plazza::Controller::AController, Plazza::Controller::AProcessManager {
		private:
			std::vector<int> fdProcess;
			Plazza::Model::IModel *_model;
			std::string _order;
			void addProcess(ISocket* socket, int _model_IModel, unsigned int nbThread);
			int takeProcessToFeed();
			void affectOrder(std::string order);
			void feedProcess(int id, std::string order);
			void notifyController(char input);
			std::vector<std::string> ParseCommandLine(std::string order);
			void control();
		public:
			ProcessManagerSockets();
			virtual ~ProcessManagerSockets() {};
		};
	}
}

#endif
