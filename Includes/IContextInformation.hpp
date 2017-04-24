#ifndef ICONTEXTINFORMATION_HPP_
# define ICONTEXTINFORMATION_HPP_

#include "IStrategyInformation.hpp"

namespace Plazza {
	class IContextInformation {

	public:
		virtual void ExecuteStrategy(std::string const &fileContent) = 0;
		virtual ~IContextInformation() {};
	};
}

#endif