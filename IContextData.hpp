#ifndef ICONTEXTDATA_HPP_
# define ICONTEXTDATA_HPP_

#include "IStrategyData.hpp"

namespace Plazza {
	class IContextData {
	private:
		virtual void ExecuteStrategy() = 0;
		virtual void Context(IStrategyData *) = 0;

	public:
		virtual ~IContextData() {};
	};
}

#endif