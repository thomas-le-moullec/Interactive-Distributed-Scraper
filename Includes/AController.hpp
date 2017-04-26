#ifndef ACONTROLLER_HPP_
#define ACONTROLLER_HPP_

#include "IController.hpp"
#include "Information.hpp"

namespace Plazza {
	namespace Controller {
		class AController : public IController {
        protected:
			Plazza::Model::IModel *_model;

		public:
			virtual ~AController() {};
			virtual void 											SetCommandLine(std::string command);
			virtual std::string 							GetCommandLine();
			virtual void 											Reset();
			virtual std::vector<std::string> 	ParseCommandLine(std::string order) = 0;
			virtual void 											NotifyController(char input) = 0;

		protected:
			AController(Plazza::Model::IModel *);
			std::string 											_commandLine;
		};
	}
}

#endif
