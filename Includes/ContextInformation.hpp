#ifndef CONTEXTINFORMATION_HPP_
# define CONTEXTINFORMATION_HPP_

#include "IContextInformation.hpp"

namespace Plazza {
	class ContextInformation : public IContextInformation {
	private:
		Plazza::IStrategyInformation *_strategy;

	public:
		std::vector<std::string> ExecuteStrategy(std::string const &fileContent);
		ContextInformation(Plazza::IStrategyInformation *);
		virtual ~ContextInformation() {};

	};
}

#endif
