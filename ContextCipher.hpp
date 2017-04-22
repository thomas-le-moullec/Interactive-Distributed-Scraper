#ifndef CONTEXTCIPHER_HPP_
# define CONTEXTCIPHER_HPP_

#include "IContextCipher.hpp"

namespace Plazza {
	class ContextCipher : Plazza::IContextCipher {
	private:
		Plazza::IStrategyCipher *_strategy;
		void ExecuteStrategy();
		void Context(Plazza::IStrategyCipher *);

	public:
		ContextCipher();
		virtual ~ContextCipher() {};
	};
}

#endif