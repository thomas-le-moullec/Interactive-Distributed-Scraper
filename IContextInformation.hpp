#ifndef ICONTEXTINFORMATION_HPP_
# define ICONTEXTINFORMATION_HPP_

#include "IStrategyInformation.hpp"

namespace Plazza {
	class IContextInformation {
	private:
		virtual void ExecuteStrategy(std::string const &fileContent) = 0;
		virtual void Context(IStrategyInformation *) = 0;

	public:
		virtual ~IContextInformation() {};
	};
}

#endif