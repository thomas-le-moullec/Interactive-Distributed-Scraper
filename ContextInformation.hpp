#ifndef CONTEXTINFORMATION_HPP_
# define CONTEXTINFORMATION_HPP_

#include "IContextInformation.hpp"

namespace Plazza {
	class ContextInformation : public IContextInformation {
	private:
		Plazza::IStrategyInformation *_strategy;
		void ExecuteStrategy(std::string const &fileContent);
		void Context(Plazza::IStrategyInformation *);

	public:
		ContextInformation();
		virtual ~ContextInformation() {};

	};
}

#endif
