#ifndef ACONTROLLER_HPP_
# define ACONTROLLER_HPP_

#include "IController.hpp"
#include "IModel.hpp"

namespace Plazza {
	namespace Controller {
		class AController : Plazza::Controller::IController {
		private:
			Plazza::Model::IModel *_model;
			std::string commandLine;
			virtual void reset() = 0;
			virtual void notifyController(char input) = 0;
			virtual void setCommandLine(std::string command);
			virtual std::string getCommandLine();
			virtual std::vector<std::string> ParseCommandLine(std::string order) = 0;

		public:
			virtual ~AController() {};

		protected:
			AController();
		};
	}
}

#endif
