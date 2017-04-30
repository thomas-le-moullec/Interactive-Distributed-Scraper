#ifndef ACONTROLLER_HPP_
#define ACONTROLLER_HPP_

#include "IController.hpp"
#include "Information.hpp"

namespace Plazza {
	namespace Controller {
		class AController : public IController {
		public:
			virtual ~AController() {};
			virtual void 											Reset();
			virtual std::vector<std::string> 	ParseCommandLine(std::string order) = 0;
			virtual void 											NotifyController(std::string) = 0;

		protected:
			AController(Plazza::Model::IModel *);
			Plazza::Model::IModel 						*_model;
			std::string 											_commandLine;
		};
	}
}

#endif
