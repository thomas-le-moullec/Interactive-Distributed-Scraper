#ifndef CONTEXTINFORMATION_HPP_
# define CONTEXTINFORMATION_HPP_

#include "IContextInformation.hpp"

namespace Plazza {
	class ContextInformation : Plazza::IContextInformation {
	private:
		Plazza::IStrategyInformation *_strategy;
		void ExecuteStrategy();
		void Context(Plazza::IStrategyInformation *);

	public:
		ContextInformation();
		virtual ~ContextInformation() {};

	};
}

#endif