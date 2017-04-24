#ifndef ICONTEXTINFORMATION_HPP_
# define ICONTEXTINFORMATION_HPP_

#include "IStrategyInformation.hpp"
#include <vector>

namespace Plazza {
	class IContextInformation {

	public:
		virtual std::vector<std::string> ExecuteStrategy(std::string const &fileContent) = 0;
		virtual ~IContextInformation() {};
	};
}

#endif