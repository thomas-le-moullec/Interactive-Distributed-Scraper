#ifndef CONTEXTCIPHER_HPP_
# define CONTEXTCIPHER_HPP_

#include "IContextCipher.hpp"

namespace Plazza {
	class ContextCipher : public IContextCipher {
	private:
		Plazza::IStrategyCipher *_strategy;

	public:
		std::string ExecuteStrategy();
		ContextCipher(Plazza::IStrategyCipher *);
		virtual ~ContextCipher() {};
	};
}

#endif
