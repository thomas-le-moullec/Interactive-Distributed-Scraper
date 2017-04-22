#ifndef CONTEXTDATA_HPP_
# define CONTEXTDATA_HPP_

#include "IContextData.hpp"

namespace Plazza {
	class ContextData : Plazza::IContextData {
	private:
		Plazza::IStrategyData *_strategy;
		void ExecuteStrategy();
		void Context(Plazza::IStrategyData *);

	public:
		ContextData();
		virtual ~ContextData() {};

	};
}

#endif