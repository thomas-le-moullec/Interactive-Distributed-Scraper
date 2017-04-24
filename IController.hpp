#ifndef ICONTROLLER_HPP_
#define ICONTROLLER_HPP_

#include <iostream>
#include <vector>

namespace Plazza {
	namespace Controller {
		class IController {
        public:
            virtual ~IController(){};
						virtual void NotifyController(char input) = 0;
						virtual void Reset() = 0;
						virtual void SetCommandLine(std::string command) = 0;
						virtual std::string GetCommandLine() = 0;
						virtual std::vector<std::string> ParseCommandLine(std::string) = 0;
		};
	}
}

#endif
